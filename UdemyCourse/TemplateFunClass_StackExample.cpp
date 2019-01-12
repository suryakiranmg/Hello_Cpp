
#include <iostream>
using namespace std;

template <class G >
class Stack
{
    private:
        G *stk;
        int top;
        int size;
    public:
        //constructor
        Stack(int size)
        {
            this->size = size;
            top = -1;
            stk = new G[size];
        }
        //prototypes of facilitators
        void push(G num);
        G pop();
};

//Definitions of facilitators
template <class G >
void Stack<G> :: push(G num)
{
    if(top == size-1) cout<<"Stack Full"<<endl;
    else stk[++top] = num;
}

template<class G>
G Stack<G> :: pop()
{
    if(top == -1) cout<<"Stack Empty"<<endl;
    else return(stk[top--]);
}

//main function
int main()
{
    Stack<float> s(3);
    s.push(2);s.push(5);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;    
}


