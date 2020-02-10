#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

struct Node //character node -- Linked List
{
    int data;
    struct Node *next;
}*top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
    int x=-1;
    if(top == NULL)
    printf("Stack Empty\n");
    else
    {
        t=top;
        top = top->next;
        x=t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}

int isBalanced(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(') push(exp[i]);
        else if (exp[i]==')')
        {
            if(top == NULL) return 0;
            pop();
        }
    }
    if(top == NULL) return 1; //balanced
    else return 0;
}

int InStackprecedence(char x)
{
    if(x=='+' || x=='-') return 2;
    else if (x=='*' || x=='/') return 4;
    else if(x=='^') return 5;
    else if(x=='(') return 0;
    return -1;
}

int OutStackprecedence(char x)
{
    if(x=='+' || x=='-') return 1;
    else if (x=='*' || x=='/') return 3;
    else if(x=='^') return 6;
    else if(x=='(') return 7;
    else if(x==')') return 0;
    return -1;
}

int isOperand(char x)
{
    if(x=='+' || x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')') return 0; //yes
    else return 1;
}

char* InfixToPost(char *infix)
{
    int i=0,j=0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc(sizeof(char)*(len+2));
    
    while(infix[i]!= '\0')
    {
        if(isOperand(infix[i])) postfix[j++] = infix[i++];
        else
        {
            if(OutStackprecedence(infix[i])>InStackprecedence(top->data))
                push(infix[i++]);
            else if(OutStackprecedence(infix[i])<InStackprecedence(top->data))
                postfix[j++] = pop();
            else 
            {
                i++;
                pop();
            }
        }
    }
    while(top != NULL) postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int Eval(char *postfix)
{
    int i=0,x1,x2,r=0;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            x2=pop(); x1 = pop();
            switch(postfix[i])
            {
                case '+': r=x1+x2; break;
                case '-': r=x1-x2; break;
                case '*': r=x1*x2; break;
                case '/': r=x1/x2; break;
            }
            push(r);
        }
    }
    return top->data;
}
int main()
{   
    char *postfix = "35*62/+4-";
    printf("Result is %d",Eval(postfix));
    
    return 0;
}
