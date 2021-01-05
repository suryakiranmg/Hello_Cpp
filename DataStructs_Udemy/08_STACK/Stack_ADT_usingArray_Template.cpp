
#include<iostream>
using namespace std;

template<class T>
class Stack
{
    private:
        T *st; int size; int top;
    public:
        Stack()
         {
           size = 10; top = -1; st = new T[size];
         }
        Stack(int size)
         {
           this->size = size; top = -1; st = new T[this->size];            
         }     
        void push(T x);
        T pop();
        T peek(int index);
        T StackTop();
        int isEmpty();
        int isFull();
        void Display();
};

template<class T>
void Stack<T>::push(T x)
{
    if(isFull()) cout<<"Stack Overflow"<<endl;
    else
    {
        top++;
        st[top]=x;
    }
}

template<class T>
T Stack<T>::pop()
{
    T x=-1;
    if(isEmpty()) cout<<"Stack Underflow"<<endl;
    else 
    {
        x = st[top]; top--;
    }
    return x;
}

template<class T>
T Stack<T>::peek(int index)
{
    T x=-1;
    if(top-index+1 < 0) cout<<"Invalid index"<<endl;
    else
        x = st[top-index+1];
    return x;
}

template<class T>
T Stack<T>::StackTop()
{
    if(isEmpty()) return -1;
    return st[top];
}

template<class T>
int Stack<T>::isFull()
{
    return top == size-1;
}

template<class T>
int Stack<T>::isEmpty()
{
    return top==-1;
}

template<class T>
void Stack<T>::Display()
{
for(int i=top;i>=0;i--)
  cout<<st[i]<<" ";
cout<<endl;
}
 
int main()
{
    Stack<char> stk(4);
    stk.push('i');
    stk.push('k');
    stk.push('u');
    stk.push('s');
    
    stk.Display();
    cout<<stk.peek(2)<<endl;
    cout<<stk.StackTop()<<endl;
    return 0;
    
}
    
            

