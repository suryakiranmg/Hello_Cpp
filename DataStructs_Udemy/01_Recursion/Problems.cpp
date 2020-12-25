#include <iostream>
using namespace std;

int Sum(int n)                              // Sum using Recursion
{
    if(n==0) return 0;
    else return n+Sum(n-1);
}

int Sum_DirectFormula(int n)                // Sum - Direct Formula
{
    return n*(n+1)/2;
}

int Factorial(int n)                        // Factorial using Recursion
{
    if(n==0) return 1;
    else return n*Factorial(n-1);
}

int Power(int m, int n)                     // Power using Recursion
{
    if(n==0) return 1;
    else return m*Power(m,n-1);
}

int Power_Simplified(int m, int n)          // Power using Recursion - More efficient
{
    if(n==0) return 1;
    
    if(n%2==0) return Power_Simplified(m*m,n/2);
    else return m*Power_Simplified(m*m,(n-1)/2);
}

float TaylorSeries(int x, int n)             // Taylor Series using Recursion - upto n terms - using Horner's Rule
{
    static float s=1;
    if(n==0) return s;
    
    s = 1 + (float)x/n *s;
    return TaylorSeries(x,n-1);
}

float TaylorSeries_Iterative(int x, int n)  // Taylor Series - Iterative
{
    static float s=1, num=1, den=1;

    for(int i=1; i<=n; i++)
    {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

int Fib(int n)                              // Fibonacci Series - Recursive
{
    if(n<=1) return n;
    else return Fib(n-2)+Fib(n-1);
}

int Fib_Iter(int n)                         // Fibonacci Series - Iterative
{
    int f0 = 0, f1 = 1, s=0;
    if(n<=1) return n;
    for(int i=2; i<=n; i++)
    {
        s=f0+f1;
        f0=f1;
        f1=s;
    }
    return s;
}

int NCR(int n, int r)                       // nCr - Recursive using Pascal's Triangle
{
    if(n==r || r==0) return 1;
    else return NCR(n-1,r-1) + NCR(n-1,r);
}

int main()
{
    cout<<"Sum of n natural Nos: "<<Sum(5)<<endl;
    cout<<"Sum of n natural Nos: "<<Sum_DirectFormula(5)<<endl<<endl;
    
    cout<<"Factorial of n: "<<Factorial(5)<<endl<<endl;
    
    cout<<"Power of m^n: "<<Power(2,8)<<endl;
    cout<<"Power of m^n: "<<Power_Simplified(2,8)<<endl<<endl;
    
    cout<<"Taylor Series e^x to n terms: "<<TaylorSeries(1,10)<<endl;
    cout<<"Taylor Series e^x to n terms - iterative: "<<TaylorSeries_Iterative(1,10)<<endl<<endl;
    
    cout<<"Fibonacci Series- Recursive: "<<Fib(6)<<endl;
    cout<<"Fibonacci Series- Iterative: "<<Fib_Iter(6)<<endl<<endl;
    
    cout<<"nCr - Recursive: "<<NCR(5,3)<<endl<<endl;
    
    return 0;
}
