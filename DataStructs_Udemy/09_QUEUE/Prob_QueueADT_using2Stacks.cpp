#include<iostream>
#include<stack>

using namespace std;

class Queue
{
    private:
        stack<int> in_stk;  //enqueue stack
        stack<int> out_stk; //dequeue stack
    public:
        Queue() {;}
        void enqueue(int x);
        int dequeue();
};

void Queue :: enqueue(int x)
{
    in_stk.push(x);
}

int Queue :: dequeue()
{
    int x=-1;
    if(out_stk.empty()) //dequeue stack empty
    {
        if(in_stk.empty()) //and enqueue stack empty
        {
            cout<<"Queue Underflow";
            return x;
        }
        else 
        {
            // move elments from enqueue stack to dequeue stack
            while(!in_stk.empty())
            {
                out_stk.push(in_stk.top());
                in_stk.pop();
            }
        }
    }
    x = out_stk.top(); // dequeue stack out
    out_stk.pop();
    return x;
}

int main()
{
    int A[] = {1,3,5,7,9}; int n=sizeof(A)/sizeof(A[0]);
    
    Queue q;
    cout<<"EnQueue ";
    for(int i=0; i<n; i++ ) 
    {
        q.enqueue(A[i]);
        cout<<A[i]<<" ";
    }
    
    cout<<endl<<"DeQueue ";
    for(int i=0; i<n; i++ ) 
    {
        cout<<q.dequeue()<<" <-- ";
    }
    
    return 0;
}

