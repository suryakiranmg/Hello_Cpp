// -------------------------- DEQueue (Double Ended Queue) -- using Array ------------------------  // --- not FIFO (Insert / Delete from any side)
#include<iostream>
using namespace std;

class DEQueue
{
    private:
        int front;
        int rear;
        int size;
        int *Q;
    public:
        DEQueue(int size)  { front =-1; rear = -1; this->size = size; Q = new int[size]; }
        ~DEQueue() { delete []Q; Q=nullptr; }
        void display();
        bool isEmpty() { if(front==rear)    return true; else return false; }
        bool isFull()  { if(rear == size-1) return true; else return false; }
        void enqueue_front(int x);
        void enqueue_rear(int x);
        int dequeue_front();
        int dequeue_rear();
};

void DEQueue :: display()
{
    for(int i= front+1; i<=rear; i++)
    {
        cout<<"<-- "<<Q[i];
    }
    cout<<endl;
}

void DEQueue :: enqueue_rear(int x)
{
    if(isFull()) cout<<"DEQueue Full"<<endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int DEQueue :: dequeue_front()
{
    int x=-1;
    if(isEmpty()) cout<<"Empty DEQueue"<<endl;
    else
    {
        front++;
        x=Q[front];

    }
    return x;
}

int DEQueue :: dequeue_rear()
{
    int x=-1;
    if(rear==-1) cout<<"Empty DEQueue"<<endl;
    else
    {
        x=Q[rear];
        rear--;
    }
    return x;
}


void DEQueue :: enqueue_front(int x)
{
    if(front == -1) cout<<"DEQueue Overflow"<<endl;
    else
    {
        Q[front]=x;
        front--;
    }
}

int main()
{
    int A[] = { 2,3,4,5 }; int n = sizeof(A)/sizeof(A[0]);
    
    
    DEQueue dq(n);
    
    for(int i=0; i<n; i++) dq.enqueue_rear (A[i]);
    dq.enqueue_rear(10);//overflow
    dq.display();
    for(int i=0; i<n; i++) dq.dequeue_front();
    dq.dequeue_front();//underflow
    
    int B[] = { -2,-3,-4}; n = sizeof(B)/sizeof(B[0]);
    for(int i=0; i<n; i++) dq.enqueue_front (B[i]);
    dq.enqueue_front(10);
    dq.display();
    for(int i=0; i<n; i++) dq.dequeue_rear();
    
    return 0;
}
