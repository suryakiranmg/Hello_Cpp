#include <iostream>                          //--- Shell Sort
using namespace std;


void ShellSort(int A[], int n)
{
    for(int gap = n/2; gap>=1; gap = gap/2)
    {
        for(int i=gap; i<n; i++)
        {
            int temp = A[i];
            int j=i-gap;
            while(j>=0 && A[j]>temp)
            {
                A[j+gap] = A[j];
                j=j-gap;
            }
            A[j+gap] = temp;
        }
    }
}

int main(void)
{
   int A[] = {3,2,6,3,4,9,10,45,33,1};
   int n = sizeof(A)/sizeof(A[0]);
   
   ShellSort(A,n);
   
   for(int i=0; i<n; i++)
    {
      cout<<" "<<A[i];
    }

    return 0;
}
