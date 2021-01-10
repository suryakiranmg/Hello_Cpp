// Circular Queue ---- circular behaviour achieved using mode operation
#include<iostream>
using namespace std;

class Circular_Queue
{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        Circular_Queue(int size) { this->size = size; front=0; rear=0; Q=new int[size]; }
        ~Circular_Queue() { delete []Q; }
        bool isFull() { if((rear+1)%size == front) return true; else return false; }
        bool isEmpty() { if(front == rear) return true; else return false; }
        void enqueue(int x);
        int dequeue();
        void display();
};

void Circular_Queue :: enqueue(int x)
{
    if(isFull()) cout<<"Queue Overflow"<<endl;
    else
    {
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}

int Circular_Queue :: dequeue()
{
    int x=-1;
    if(isEmpty()) cout<<"Queue Underflow"<<endl;
    else 
    {
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}

void Circular_Queue :: display()
{
    for(int i=(front+1)%size; i != (rear+1)%size ; i=(i+1)%size)
    {
        cout<<"<--"<<Q[i];
    }
    cout<<endl;
}


int main()
{
    int A[] = { 1,3,5,7,9}; int n = sizeof(A)/sizeof(A[0]);
    Circular_Queue cq(n+1);
    
    for(int i=0; i<n; i++) cq.enqueue(A[i]);
    cq.display();
    
    cq.enqueue(10); // Overflow
    
    for(int i=0; i<n; i++) cq.dequeue();
    
    cq.dequeue();  // Underflow
    
    return 0;
}
