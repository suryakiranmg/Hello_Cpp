#include<iostream>
using namespace std;

class Queue
{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        Queue(int size);
        ~Queue() { delete[]Q; }
        bool isFull();
        bool isEmpty();
        void enqueue(int x);
        int dequeue();
        void display();
};

Queue::Queue(int size)
{
    this->size = size;
    front =-1; rear = -1;
    Q = new int[size];
}

bool Queue :: isFull()  { if(rear == size-1) return true; else return false; }
bool Queue :: isEmpty() { if(rear == front)  return true; else return false; }

void Queue :: enqueue(int x)
{
    if(isFull())  cout<<"Queue Overflow"<<endl;
    else 
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue :: dequeue()
{
    int x=-1;
    if(isEmpty()) cout<<"Queue Underflow"<<endl;
    else x = Q[++front];
    return x;
}

void Queue :: display()
{
    for(int i = front+1; i<= rear; i++)
    {
        cout<<"<-- "<<Q[i];
    }
    cout<<endl;
}

int main()
{
    int A[]={3,5,7,9}; int n= sizeof(A)/sizeof(A[0]); cout<<n<<endl;
    Queue q(n);
    
    for(int i=0; i<n; i++) { q.enqueue(A[i]); }
    q.display();
    
    q.enqueue(10); // overflow
    
    for(int i=0; i<n; i++) q.dequeue();
    q.dequeue();  // underflow
    

    return 0;
}
