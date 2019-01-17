#include<iostream>
using namespace std;

template<typename T>
void funct(T p)
{
    p();
}

int main()
{
 
    [](int x, int y){cout<<"Sum is "<<x+y<<endl;}(4,6);
    
    cout<<([](int x, int y){return x+y;}(4,6));
    
    int a = [](int x, int y)->int{return x+y;}(4,6);
    cout<<endl<<a<<endl;
    
   int b=20; 
   auto fun =  [b](){cout<<b<<endl;};
   fun();
   b++; //will not change the value used in lambda fun
   fun();
   
   auto fun1 = [&b](){cout<<b++<<endl;};
   fun1();   fun1();
   
   //To send lambda exprn to a function as parameter
   funct(fun);
   funct(fun);
   funct(fun1);
   funct(fun1);
   
   
}
