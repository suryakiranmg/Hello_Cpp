#include <iostream>
using namespace std;

void swap(int* x, int* y)
{
    int temp = *x; *x = *y; *y = temp;
}

void BubbleSort(int A[], int n)                         //--- Bubble Sort
{
    int flag;
    for(int i=0; i<n-1; i++)
    {
        flag=0;
        for(int j=0; j<n-1-i; j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0) return;
    }
}

void InsertionSort(int A[], int n)                      //--- Insertion Sort
{
    int j,key;
    for(int i=1;i<n; i++)
    {
        key = A[i];
        j=i-1;
        while(j>=0 && A[j]>key)
        {
            A[j+1] = A[j];   
            j--;
        }
        A[j+1]=key;
    }
}

void SelectionSort(int A[], int n)                      //--- Selection Sort
{
    for(int i=0; i<n-1; i++)
    {
        int k=i;
        for(int j=i; j<n; j++)
        {
            if(A[j]<A[k])
            {
                k=j;
            }
        }
       swap(&A[i], &A[k]);
    }
}

int Partition_QuickSort(int A[], int low, int high)     //--- Quick Sort
{
    int pivot = A[low];
    int i= low+1; 
    int j= high;
    while(1)
    {
        while(i<=j && A[i]<= pivot) { i++; }
        while(j>=i && A[j]>pivot) { j--; }
        if(j<i) break;
        else swap(&A[i], & A[j]);
    }
    swap(&A[low], &A[j]);
    return j;
}

void QuickSort(int A[], int low, int high)
{
    if(low<high)
    {
        int p = Partition_QuickSort(A, low, high);
        QuickSort(A, low, p-1);
        QuickSort(A, p+1, high);
    }
}

void Merge(int A[], int low, int mid, int high)         //--- Merge Sort
{
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high+1]; // Aux Array
    while(i<=mid && j<=high)
    {
        if(A[i]<A[j]) B[k++]   = A[i++];
        else B[k++] = A[j++];
    }
    while(i<=mid)  B[k++]   = A[i++];
    while(j<=high) B[k++]   = A[j++];
    //Copy back to A
    for(int i=low; i<=high; i++) A[i] = B[i]; 
}

void Itr_MergeSort(int A[], int n)
{
    int p;
    for(p=2; p<=n; p=p*2) // 2-way merge
    {
        for(int i=0; i+p-1<n; i=i+p)
        {
            int low = i, high = i+p-1, mid = (low+high)/2;
            Merge(A, low, mid, high);
        }
    }
    //If n odd, merge last elemt
    if(p/2<n) Merge(A ,0 , p/2 -1, n-1); 
}

void Recur_MergeSort(int A[], int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        //Partition to sublists
        Recur_MergeSort(A, low, mid);
        Recur_MergeSort(A, mid+1, high);
        
        //Merge sublists
        Merge(A, low, mid, high);
    }
}

int FindMax(int A[], int n)                         //--- Count Sort
{
    int max = A[0];
    for(int i=1; i<n; i++)
    {
        if(max<A[i]) max = A[i];
    }
    return max;
}

void CountSort(int A[], int n)
{
    int i,j;
    
    int max = FindMax(A, n);
    int* count = new int[max+1];
    
    // Initialize count array to 10
    for(i=0; i<max+1; i++)  count[i] = 0;
    // Update count array based on array
    for(i=0; i<n; i++) count[A[i]]++;
    
    i=0; j=0;
    // Update A with sorted elements
    while(i<max+1)   
    {
       if(count[i]>0)
       {
           A[j++]=i;
           count[i]--;
       }
       else i++;
    }
    // Delete heap 
    delete[] count;
}

int main()
{
   int A[] = {3,2,6,3,4,9,10,45,33,1};
   
   int n = sizeof(A)/sizeof(A[0]);
   
   //BubbleSort(A,n);
   //InsertionSort(A,n);
   //SelectionSort(A,n);
   //QuickSort(A, 0, n-1);
   //Itr_MergeSort(A,n);
   //Recur_MergeSort(A, 0, n-1);
   CountSort(A,n);
   
   for(int i=0; i<n; i++)
   {
      cout<<" "<<A[i];
   }

   return 0;
}
