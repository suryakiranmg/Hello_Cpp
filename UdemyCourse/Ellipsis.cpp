#include<iostream>
#include<memory>
#include<cstdarg>
using namespace std;

int Sum(int n, ...)
{
    va_list list;
    va_start (list,n);
    
    int sum=0;
    for(int i=0; i<n;i++)
        {
         //retrieve variable from list
            int x = va_arg(list,int); //mention also the data type of argument
            sum += x;
        }
    return sum;
}

int main()
{
    cout<<Sum(3, 10,20,30)<<endl;
    cout<<Sum(5, 1,2,3,4,5)<<endl;
}
