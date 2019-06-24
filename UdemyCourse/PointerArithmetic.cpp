
#include <bits/stdc++.h>
using namespace std; 


int main()
{
    int A[]{1,2,3,4,5};
    int *p = A;
    int *q = &A[3];
    
    cout<<p<<" "<<q<<" "<<A<<endl; // A gives address of 1st 
    cout<<*p<<" "<<*q<<endl;
    cout<<(p-q)<<" "<<(q-p)<<endl;
    cout<<3[A]<< " "<<A[3]<<" "<<p[3]<<endl<<endl; //Alternate representations
    
    //Dynamic Memory allocation
    float *ptr = new float[2];
    *ptr = 3.5; *(ptr+1) = 3.7;
    cout<<ptr<<" "<<*ptr<<endl; 
    cout<<ptr+1<<" "<<ptr[1]<<endl;
    
    delete []ptr;
    ptr = nullptr;
    
    cout<<ptr<<endl;
    
    // Function Pointer -- runtime polymorphism
    // One function ptr can point to any function with the same signature
    int (*suki)(int, int);
    suki = max;
    cout<<"Max: "<<(*suki)(10,5)<<endl;
    suki = min;
    (suki) = min;
    cout<<"Min: "<<(*suki)(10,5)<<endl;
    
}

