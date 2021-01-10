// -------------------------- Queue -- using Link List ------------------------  //
#include<iostream>
using namespace std;

class Node
{
    public: 
        int data;
        Node *next;
};

class Queue
{
    private:
        Node* front;
        Node* rear;
    public:
        Queue() { front = rear = nullptr; }
        ~Queue();
        void enqueue(int x);
        int dequeue();
        void display();
        bool isEmpty() { if(front == nullptr) return true; else return false; }
};

Queue :: ~Queue()
{
    Node *t = front;
    while(front)
    {
        front = front->next;
        delete t;
        t=front;
    }
}

void Queue :: enqueue(int x)
{
    Node *t = new Node;
    if(t==nullptr) cout<<"Heap Full"<<endl;
    else
    {
        t->data = x; t->next = nullptr;
        
        if(front==nullptr)//first node
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear=t;
        }
    }
}

int Queue :: dequeue()
{
    int x=-1; Node *t;
    if(isEmpty()) cout<<"Empty Queue"<<endl;
    else
    {
        x=front->data;
        t=front;
        front = front->next;
        delete t; 
    }
    return x;
}

void Queue :: display()
{
    Node *t=front;
    while(t)
    {
        cout<<"<--"<<t->data;
        t=t->next;
    }
    cout<<endl;
}

int main()
{
    int A[] = { 1,3,5,7,9}; int n = sizeof(A)/sizeof(A[0]);
    
    Queue q;
    for(int i=0; i<n; i++) q.enqueue(A[i]);
    
    q.display();
    
    for(int i=0; i<n; i++) q.dequeue();
    q.dequeue();
    
    return 0;
}
