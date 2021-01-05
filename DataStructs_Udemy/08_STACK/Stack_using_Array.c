#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *S;
};

void push(struct Stack *stk, int x)
{
    if(stk->top==stk->size-1) cout<<"Stack Overflow"<<endl;
    else
    {
        stk->top++;
        stk->S[stk->top] = x;
    }
    
}

int pop(struct Stack *stk)
{
    int x=-1;
    if(stk->top==-1) cout<<"Stack Empty"<<endl;
    else
    {
        x= stk->S[stk->top];
        stk->top--;
    }
    return x;
}

int peek(struct Stack stk, int pos)
{
    int x=-1;
    if(pos<=0 || pos>stk.top+1) cout<<"Invalid Position"<<endl;
    else
    {
        x= stk.S[stk.top-pos+1];
    }
    return x;
}

int stack_top(struct Stack stk)
{
    if(stk.top == -1) return -1;
    return stk.S[stk.top];
}

int isEmpty(struct Stack stk)
{
    if(stk.top ==-1) return 1;
    else return 0;
}

int isFull(struct Stack stk)
{
    if(stk.top ==stk.size-1) return 1;
    else return 0;
}

int main()
{
    struct Stack stk;
    cout<<"Enter size : "; cin>>stk.size;
    stk.S = (int*)malloc(sizeof(stk.size));
    stk.top=-1;
    
    push(&stk,10);
    push(&stk,20);
    push(&stk,30);
    push(&stk,40);
    
    cout<<"Value at index 2: "<<peek(stk,2)<<endl;
    cout<<"value at top: "<<stack_top(stk)<<endl;
    cout<<"Pop value : "<<pop(&stk)<<endl;
    cout<<"value at top: "<<stack_top(stk)<<endl;

    return 0;
}
