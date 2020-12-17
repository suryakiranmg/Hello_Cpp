#include <iostream>                          //--- Bin/Bucket Sort
using namespace std;

// Find Max value
int FindMax(int A[], int n)                
{
    int max = A[0];
    for(int i=1; i<n; i++)
    {
        if(max<A[i]) max = A[i];
    }
    return max;
}

// Linked List & Functions
class Node
{
    public: 
        int data;
        Node* next;
};

void Insert(Node** ptrBins, int index)
{
    Node* temp = new Node; temp->data = index; temp->next = nullptr;
    
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

//------Bin/Bucket Sort
void BucketSort(int A[], int n)
{
    int max = FindMax(A,n);
    Node** Bins = new Node*[max+1];
    // Initialise all to 0
    for(int i=0; i<max+1; i++) Bins[i] = nullptr;
    // Insert each value to corresponding Bin
    for(int i=0; i<n; i++) Insert(Bins, A[i]);
    //Update A with sorted elements
    int i=0,j=0;
    while(i<max+1)
    {
        while(Bins[i]!=nullptr)
        {
            A[j++]=Delete(Bins,i);
        }
        i++;
    }
    delete[] Bins;
}


int main()
{
    int A[] = {3,2,6,3,4,9,10,45,33,1};
   
   int n = sizeof(A)/sizeof(A[0]);

   BucketSort(A,n);
   
   for(int i=0; i<n; i++)
   {
      cout<<" "<<A[i];
   }

   return 0;
}
