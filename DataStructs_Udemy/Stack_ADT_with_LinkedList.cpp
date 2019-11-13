#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node * next;
};
class Stack
{
private:
    Node * top;
public:
    Stack(){top = NULL;} //no size for linked list
    void push(int x);
    int pop();
    void Display();
};


void Stack::push(int x)
{
    Node *t = new Node;
    //check node created?
    if(t==NULL) cout<<"Stack overflow"<<endl;
    else
    {
        t->data = x;
        t->next = top;
        top=t;
    }
}

int Stack::pop()
{
    int x=-1;
    if(top == NULL) cout<<"Stack Empty"<<endl;
    else 
    {
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

void Stack::Display()
{
Node *t = top;
while(t!= NULL)
{
    cout<<t->data<<" ";
    t=t->next;
}
cout<<endl;
}
 
int main()
{
    Stack stk;
    stk.push(5);
    stk.push(6);
    stk.push(7);
    stk.push(8);
    stk.push(9);
    
    stk.Display();
    stk.pop();
    stk.Display();
  
    return 0;
    
}
    
            

