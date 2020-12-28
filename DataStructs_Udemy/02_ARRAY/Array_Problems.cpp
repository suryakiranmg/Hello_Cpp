#include<iostream>
using namespace std;

int TheMissingElement_Sorted(int A[],int n) // --------------------Missing Element in sorted array
{
    int diff = A[0];
    for(int i=0; i<n;i++)
    {
        if(A[i]-i != diff) return (diff+i);
    }
    return -1;
}

void MissingElements_Sorted(int B[],int n) // ---------------------Missing multiple Elements in sorted array
{
    int diff = B[0];
    for(int i=0; i<n;i++)
    {
        if(B[i]-i != diff)
        {
            while(diff<B[i]-i)
            {
            cout<<diff+i<<" ";
            diff++;
            }
        }
    }
    cout<<endl;
}

void MissingElements_Unsorted(int C[],int n) // -------------------Missing Elements in unsorted array using Hash table
{
    int max=C[0], min = C[0];
    for(int i=1; i<n; i++)
    {
        if(C[i]>max) max = C[i];
        if(C[i]<min) min = C[i];
    }
    int H[max+1]={0};
    for(int i=1; i<n; i++)
    {
        H[C[i]]++;
    }
    for(int i=min; i<=max; i++)
    {
        if(H[i]==0) cout<<i<<" ";
    }
    cout<<endl;
}

void Duplicates_Sorted(int D[],int n) // --------------------------Duplicate Elements in sorted array
{
    int LastDuplicate=D[0], count=0;
    for(int i=1; i<n; i++)
    {
        if(D[i]==LastDuplicate)
        {
            count++;
        }
        if(D[i]!=LastDuplicate || i==n-1)
        {
            if(count>0) cout<<LastDuplicate<<" appears "<<count+1<<" times.  ";
            count=0;
        }
        LastDuplicate = D[i];
    }
}

void Duplicates_Sorted_Hashing(int A[],int n) // ------------------Duplicate Elements in sorted array using Hashing
{
    int H[A[n-1]-A[0]+1]={0};
    for(int i=0; i<n; i++)
    {
     H[A[i]-A[0]]++;
    }
    for(int i=0; i<A[n-1]-A[0]+1; i++)
    {
     if(H[i] >1) 
     cout<<i+A[0]<<" appears "<<H[i]<<" times.  ";
    }
     
}

void Duplicates_Unsorted_Hashing(int A[],int n) // ----------------Duplicate Elements in Unsorted array using Hashing
{
    int max=A[0], min = A[0];
    for(int i=1; i<n; i++)
    {
        if(A[i]>max) max =A[i];
        if(A[i]<min) min =A[i];
    }
    int H[max-min+1]={0};
    
    for(int i=0; i<n; i++)
    {
     H[A[i]-min]++;
    }
    for(int i=0; i<max-min+1; i++)
    {
     if(H[i] >1)
     cout<<i+min<<" appears "<<H[i]<<" times.  ";
    }
     
}

void Pair_with_SumK(int A[],int n, int sum) // --------------------Find pair of elements with Sum K(unsorted, unique elements)
{
    int max=A[0], min = A[0];
    for(int i=1; i<n; i++)
    {
        if(A[i]>max) max = A[i];
        if(A[i]<min) min = A[i];
    }
    int H[max-min+1]={0};
    for(int i=0; i<n; i++)
    {
     H[A[i]-min]++;
    }
    
    for(int i=0; i<n; i++)
    {
     H[A[i]-min]--;
     if(H[sum-A[i]-min]==1) 
     {
      cout<<A[i]<<"+"<<sum-A[i]<<"="<<sum<<endl;
     }
    }
     
}

int main()
{
    int A[] = {4,5,6,7,8,9,10,11,12,13,14,15,16,17,19};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<"The Missing Element in Sorted Array : "<<TheMissingElement_Sorted(A,n)<<endl;
    
    int B[] = {4,5,6,7,9,10,11,12,16,19};
    n = sizeof(B)/sizeof(B[0]);
    cout<<"Missing Elements in Sorted Array : ";
    MissingElements_Sorted(B,n);
    
    int C[] = {5,6,7,4,11,9,8,1,2,14};
    n = sizeof(C)/sizeof(C[0]);
    cout<<"Missing Elements in Unsorted Array : ";
    MissingElements_Unsorted(C,n);
    
    int D[] = {2,3,3,5,8,9,9,9,11,13,15,15,15,18,18};
    n = sizeof(D)/sizeof(D[0]);
    cout<<"Duplicate Elements in Sorted Array : ";
    Duplicates_Sorted(D,n);
    cout<<endl<<"Duplicate Elements in Sorted Array using hashing : ";
    Duplicates_Sorted_Hashing(D,n);
    
    int E[] = {1,18,18,55,11,10,8,7,7,55,2,1,55,55,55,1};
    n = sizeof(E)/sizeof(E[0]);
    cout<<endl<<"Duplicate Elements in Unsorted Array : ";
    Duplicates_Unsorted_Hashing(E,n);
    
    int F[] = {6,3,8,10,16,7,5,2,9,14,4,5,1,10};
    n = sizeof(F)/sizeof(F[0]);
    cout<<endl<<"Pair with Sum K, unique unsorted array : ";
    Pair_with_SumK(F,n,10);
    
    return 0;
}
