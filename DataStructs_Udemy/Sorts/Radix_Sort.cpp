#include <iostream>                          //--- Radix Sort
#include <cmath>
using namespace std;


// ------------------ Linked List & Functions-------------------- //
class Node
{
    public: 
        int data;
        Node* next;
};

void Insert(Node** ptrBins, int value, int index)
{
    Node* temp = new Node; temp->data = value; temp->next = nullptr;
    
    if(ptrBins[index]==nullptr) ptrBins[index]=temp; //head ptr
    else
    {
        Node* p = ptrBins[index];
        while(p->next != nullptr) p=p->next; //else go till end
        p->next = temp;
    }
}

int Delete(Node** ptrBins, int index)
{
    Node* p = ptrBins[index]; //headptr
    int x = p->data;
    ptrBins[index]=ptrBins[index]->next;
    delete p;
    return x;
}

// ----------------- Helper functins --------------------------- //
void InitializeBins(Node** Bins, int n)
{
    for(int i=0; i<n; i++) Bins[i]=nullptr;
}

int FindMax(int A[], int n)                
{
    int max = A[0];
    for(int i=1; i<n; i++)
    {
        if(max<A[i]) max = A[i];
    }
    return max;
}

int DigitCount(int x)
{
    int count=0;
    while(x != 0)
    {
        x =x/10;
        count++;
    }
    return count;
}


// -------------------- Radix Sort ------------------------------- //
void RadixSort(int A[], int n)
{
    int max = FindMax(A,n);
    int nrPass = DigitCount(max);                                                                                                                       
    
    Node** Bins = new Node*[10]; //10 for decimal nos
    InitializeBins(Bins,10);
    
    for(int pass=0; pass<nrPass; pass++)
     {
        // Update Bins with digit from A
        for(int i=0; i<n; i++)
        {
            int digit = (int)(A[i]/pow(10,pass))%10;
            Insert(Bins, A[i], digit);
        }
        // Update A with sorted elements from Bins
        int i=0,j=0;
        while(i<10)
        {
            while(Bins[i] != nullptr) A[j++] = Delete(Bins, i);
            i++;
        }
            
        // Initialise Bins as null before releasing
        InitializeBins(Bins,10);
     }
    delete[] Bins;
}


int main(void)
{
   int A[] = {3,2,6,3,4,9,10,45,33,1};
   int n = sizeof(A)/sizeof(A[0]);
   
   RadixSort(A,n);
   
   for(int i=0; i<n; i++)
    {
      cout<<" "<<A[i];
    }

    return 0;
}
