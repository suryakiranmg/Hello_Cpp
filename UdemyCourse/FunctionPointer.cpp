#include<iostream>
using namesapce std;
void display()
{
  cout<<"hello";
}

int main()
{
  int *p;
  a = 10;
  p = &a;
  
  //Function Pointer
  void(*fp)(); // structure definition
  fp = display; // initialisation
  
  
  cout<<p; // gives the address stored in p 
  cout<<*p; // gives the value stored in the address in p, ie 10
  
  
  (*fp)(); //function call
  
  
  
}
