#include <iostream>
using namespace std;

template <typename T>
void Swap ( T &a, T &b) //pass by reference
{
    T temp = a; a=b; b= temp;
}

template <class T>
void Swap ( T *a, T *b, int n=1 ) // pass by addr; works for arrays too
{
    T temp;
    for(int i=0; i<n; i++)
    {
        temp = a[i]; a[i] = b[i]; b[i] = temp;
    }
}

int main()
{
    int a=10,b=20;
    Swap(a,b); cout<<"a = "<<a<<" b = "<<b<<endl;  // pass by ref
    Swap(&a, &b); cout<<"a = "<<a<<" b = "<<b<<endl; // pass by addr
    
    int arr1[3] = {1,2,3}; int arr2[3] = {4,5,6};
    //print
    cout<<"arr1 = "<<*arr1<<","<<*(arr1+1)<<","<<*(arr1+2)<<endl;
    cout<<"arr2 = "<<*arr2<<","<<*(arr2+1)<<","<<*(arr2+2)<<endl;
    //swap
    Swap(arr1, arr2, 3); // pass by addr for array
    //print
    cout<<"arr1 = "<<*arr1<<","<<*(arr1+1)<<","<<*(arr1+2)<<endl;
    cout<<"arr2 = "<<*arr2<<","<<*(arr2+1)<<","<<*(arr2+2)<<endl;
    
    return 0;
}
