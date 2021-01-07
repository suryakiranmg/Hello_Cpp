#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node // Stack using link List
{
    char data;
    struct Node* next;
} *top=NULL;

// Function Prototypes
void push(char x);
char pop();
void Display();
char Peek(int index);


//------------ Infix to Postfix -- using Stack; when exprn has paranthesis & operators with R to L associativity -----------//

int InStack_Precedence(char x)
{
    if( x=='+' || x=='-' ) return 2;
    if( x=='*' || x=='/' ) return 4;
    if( x=='^' ) return 5;
    if( x=='(' ) return 0;
    return -1;
}

int OutStack_Precedence(char x)
{
    if( x=='+' || x=='-' ) return 1;
    if( x=='*' || x=='/' ) return 3;
    if( x=='^' ) return 6;
    if( x=='(' ) return 7;
    if( x==')' ) return 0;
    return -1;
}

int IsOperand(char x)
{
    if( x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')' ) return 0; // not operand
    return 1;
}

char* Convert_Infix_to_Postfix( char* infix)
{
   char* postfix = (char*)malloc(sizeof(char) * (strlen(infix)+1));
   int i=0,j=0;
   push(' '); // to avoid error while comparing in precedence
   
   while(infix[i]!='\0')
   {
       if(IsOperand(infix[i])) postfix[j++] = infix[i++];
       else
       {
           if( OutStack_Precedence(infix[i]) > InStack_Precedence(top->data) )  push( infix[i++] );
           else if ( OutStack_Precedence(infix[i]) < InStack_Precedence(top->data) ) postfix[j++] = pop();
           else 
           {
               pop(); //opening bracket in-stack and closing bracket out-stack
               i++;
           }
       }
   }
   
   // empty stack
   while(top != NULL) postfix[j++] = pop();
   
   postfix[j] = '\0';
   return postfix;
}


int main()
{
    char *infix = "a+b*c-d/e";
    char *postfix = Convert_Infix_to_Postfix (infix);
    printf(" %s", postfix);
    
    infix = "35*62/+4-";
    postfix = Convert_Infix_to_Postfix (infix);
    printf("\n %s", postfix);
    
    infix = "((a+b)*c)-d^e^f";
    postfix = Convert_Infix_to_Postfix (infix);
    printf("\n %s", postfix);
    
    return 0;
}

// Stack ADT using Link List - Function definitions
void push(char x) //------------------------------------------------------------Pop
{
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL) printf("Memory Full\n");
    else
    {
        t->data = x;
        t->next = top;
        top=t;
    }
}

char pop() //-------------------------------------------------------------------Pop
{
    char x=-1;
    if(top==NULL) printf("Stack Empty\n");
    else
    {
        struct Node *t=top;
        x=top->data;
        top=top->next;
        free(t);
    }
    return x;
}

void Display() //---------------------------------------------------------------Display
{
    struct Node *p = top;
    while(p)
    {
        printf(" %c ", p->data);
        p=p->next;
    }
    printf("\n");
}

char Peek(int index) //---------------------------------------------------------Peek
{
    struct Node *p=top;
    while(p && index-1>0) 
    {
        p=p->next; index--;
    }
    if(p) return p->data;
    else return -1;
}
