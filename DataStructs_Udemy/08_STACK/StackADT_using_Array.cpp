#include <iostream>
using namespace std;

class Stack
{
 private:
    int size;
    int top;
    int *S;
    
 public:
    Stack()
    {
        size=10;
        top = -1;
        S= new int[size];
    }
    Stack(int size)
    { 
        size = size;
        top = -1;
        S = new int[size];
    }
    //Functions
    void Push(int x);
    int Pop();
    int Peek(int index);
    int StackTop();
    int isEmpty();
    int isFull();
    void Display();
};

void Stack::Push(int x)
{
    if(isFull()) cout<<"Overflow"<<endl;
    else
    {
        top++;
        S[top]=x;
    }
}

int Stack::Pop()
{
    int x=-1;
    if(isEmpty()) cout<<"Stack Empty"<<endl;
    else
    {
        x=S[top];
        top--;
    }
    return x;
}

int Stack::Peek(int index)
{
  int x=-1;
  if(index<=0 || index>top+1) cout<<"Invalid index"<<endl;
  else
  {
      x=S[top-index+1];
  }
  return x;
}

int Stack::StackTop()
{
    if(isEmpty()) return -1;
    return S[top];
}

int Stack::isEmpty()
{
    if(top==-1) return 1;
    return 0;
}

int Stack::isFull()
{
    if(top == size-1) return 1;
    else return 0;
}

void Stack::Display()
{
    for(int i=top; i>-1; i--)
     { cout<<S[i]<<" "; }
    cout<<endl;
}

int main()
{
    Stack stk(10);
    stk.Push(10); stk.Push(20); stk.Push(30); stk.Push(40); stk.Push(50);
    stk.Display();
    
    cout<<"Peek :"<<stk.Peek(2)<<endl;
    cout<<"Stack top :"<<stk.StackTop()<<endl;

    return 0;
}
