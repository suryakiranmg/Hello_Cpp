#include <iostream>
#include<exception>
using namespace std;

class StackOverFlow: exception{};
class StackUnderFlow: exception{};

class Stack
{
 private: 
        int *stk;
        int top = -1;
        int size;
 public:
        Stack(int sz)
        { 
         size = sz;
         stk = new int[size];  
        }

        void push(int val)
        {
         if(top == size -1)
         throw StackOverFlow();
         stk[++top] = val;
        }

        int pop()
        {
         if(top == -1) 
         throw StackUnderFlow();
         return (stk[top--]);  
        }
};

int main()
{
  Stack s(4);
  s.push(10);s.push(20);s.push(55);s.push(57);
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;

 s.push(11);s.push(20);s.push(30);s.push(40);s.push(50);

}
