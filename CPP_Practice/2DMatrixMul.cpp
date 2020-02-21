//#include <bits/stdc++.h>
#include<iostream>
using namespace std; 

int main()
{
    // Matrix A
    int r1,c1; 
    cout<<"Enter r1,c1: ";
    cin>>r1>>c1; cout<<r1<<" "<<c1;
    int A[10][10];
    cout<<endl<<"Enter the elements of A[]: ";
    for(int i=0;i<r1;i++)
    {
        for(int j=0; j<c1; j++)
        {
            cin>>A[i][j];
        }
    }
    // Matrix B
    cout<<endl<<"Enter r2,c2: ";
    int r2,c2; cin>>r2>>c2; cout<<r2<<" "<<c2;
    int B[10][10];
    cout<<endl<<"Enter the elements of B[]: ";
    for(int i=0;i<r2;i++)
    {
        for(int j=0; j<c2; j++)
        {
            cin>>B[i][j];
        }
    }
    //Feasibility Check
    if(c1!=r2) 
    {
        cout<<endl<<"Multiplication Not feasible";
        return 0;
    }
    // Result of Multiplication - C
    cout<<endl<<"Result: "<<endl;;
    int C[10][10]={0};
    for(int i=0;i<r1;i++)
    {
        for(int j=0; j<c2; j++)
        {
            C[i][j]=0;
            for(int k=0; k<c1; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    //Display Result
    for(int i=0;i<r1;i++)
    {
        for(int j=0; j<c2; j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

