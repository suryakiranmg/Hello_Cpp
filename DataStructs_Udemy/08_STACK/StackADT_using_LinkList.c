#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
} *top=NULL;

void push(int x) //--------------------------------------------------------------Pop
{
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL) cout<<"Memory Full"<<endl;
    else
    {
        t->data = x;
        t->next = top;
        top=t;
    }
}

int pop() //--------------------------------------------------------------------Pop
{
    int x=-1;
    if(top==NULL) cout<<"Stack Empty"<<endl;
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
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int Peek(int index) //----------------------------------------------------------Peek
{
    struct Node *p=top;
    while(p && index-1>0) 
    {
        p=p->next; index--;
    }
    if(p) return p->data;
    else return -1;
}

int main()
{
    push(1); push(3); push(5); push(7); push(13);
    Display();
    cout<<"Top element "<<pop()<<endl;
    Display();
    cout<<"Peek index 2:  "<<Peek(2)<<endl;
    
    return 0;
}
