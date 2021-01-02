#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node *first = NULL, *second = NULL; // global head ptrs

void Create_LinkedList(int* A,int n) //-----------------------------------------Create from Array
{
    struct Node *t,*last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0]; first->next = NULL;
    
    last = first;
    for(int i=1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i]; t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display_LinkedList(struct Node* p) //--------------------------------------Display
{
    printf("\n");
    while(p != NULL)
    {
        printf("%d ",p->data);
        p= p->next;
    }
    printf("\n");
}

int Count_Nodes(struct Node*p) //-----------------------------------------------Count nodes
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

int Sum_Nodes(struct Node* p) //------------------------------------------------Sum nodes
{
    int sum=0;
    while(p!=NULL)
    {
        sum += p->data;
        p=p->next;
    }
    return sum;
}

int Max_Element(struct Node* p) //----------------------------------------------Find max element
{
    int max =p->data;
    while(p!=NULL)
    {
        if(p->data > max) max = p->data;
        p=p->next;
    }
    return max;
}

struct Node* LinearSearch_LinkedList(struct Node* p, int key) //----------------Linear Search
{
    struct Node* tail = NULL;  //tail pointer
    while(p != NULL)
    {
        if(p->data == key)
        {
            //if key found, move it to front
            tail->next = p->next; 
            p->next = first;
            first = p;
            
            return p;
        }
        tail=p; 
        p=p->next;
    }
    return NULL;
}

void Insert(struct Node* p, int index, int x) //--------------------------------Insert at index
{
    if(index < 0 || index >Count_Nodes(first)) return;
    
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node)); t->data = x;t->next = NULL; 
    
    if(index == 0) // Insert at head
    {
        t->next = first; first = t;
    }
    else
    {
        for(int i=0; i<index; i++) p=p->next;
        // Insert at index
        t->next = p->next; p->next = t;
    }
}

void Insert_SortedLinkedList(struct Node* p, int x) //--------------------------Insert in sorted list
{
    struct Node *t,*q;
    t = (struct Node*)malloc(sizeof(struct Node)); t->data = x;t->next =NULL;
    
    if(first == NULL) { first =t; }
    else
    {
        while(p && x > p->data)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next = first; first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node*p, int index) //-----------------------------------------Delete from index
{
    if(index < 0 && index > Count_Nodes(p)) return -1;
    
    struct Node *q; int x;
    if(index == 1)
    {
        q = first; x = first->data;
        first = first->next;
        free(q); return x;
    }
    else
    {
        for(int i=0;i<index-1; i++)
        {
            q=p; p=p->next;
        }
        q->next = p->next;
        x=p->data;
        free(p); return x;
    }
}

int IsSorted(struct Node *p) //-------------------------------------------------Is Sorted ?
{
    int x = p->data;
    while(p)
    {
        if(x > p->data) 
        {
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}

void Remove_Duplicates(struct Node* p) //---------------------------------------Remove duplicates in sorted list
{
    struct Node *q = p->next;
    while(q)
    {
        if(p->data != q->data)
        {
            p=q;
            q= q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q=p->next;
        }
    }
}

void Reverse_LinkedList(struct Node* p) //--------------------------------------Reverse using sliding ptrs
{
    struct Node *q=NULL,*r=NULL;
    
    while(p)
    {
        //---Slide one place ahead : -r-q-p-
        r=q;
        q=p;
        p=p->next;
        //---Reverse link
        q->next = r;
    }
    first = q;
}

void Reverse_LinkedList_Array(struct Node *p) //--------------------------------Reverse using array
{
    int *A = (int*)malloc(sizeof(int)*Count_Nodes(p));
    struct Node *q = p;
    int i=0;
    while(q) // Copy data to array
    {
        A[i++]=q->data;
        q=q->next;
    }
    q=p; i--;
    while(q) // Reverse copy
    {
        q->data = A[i--];
        q=q->next;
    }
}

void Concat_LinkedList(struct Node *p, struct Node *q) //-----------------------Concatenate Linked Lists
{
    first = p;
    while(p->next)
    {
        p = p->next;
    }
    p->next = q;
}

void Merge_LinkedList(struct Node* p, struct Node* q) //------------------------Merge Linked Lists
{
    struct Node *last;
    if(p->data < q->data) //set head ptr & 1st node
    {
        first = last = p; 
        p = p->next;
        last->next = NULL;
    }
    else 
    {
        first = last = q;
        q = q->next;
        last->next = NULL;
    }
    while( p && q) // merge the rest
    {
        if(p->data < q->data)
        {
            last->next = p; last = p; p=p->next; last->next = NULL;
        }
        else
        {
            last->next = q; last = q; q= q->next; last->next = NULL;
        }
    }
    //copy the rest
    if(p) last->next = p;
    else last->next = q;
}

int IsLoop_LinkedList(struct Node *p) //----------------------------------------Check for loop?
{
    struct Node *q, *r; q=r=p;
    do
    {
        p=p->next; //p moves 1 step & q moves 2 steps ahead
        q=q->next;
        q = (q?q->next:q);
    }
    while(p && q && p != q);
    
    if(p==q) return 1; //p meets q if loop
    else return 0; //q reaches null; no loop
}

int main()
{
    int A[] = {3,5,7,10,15}; int n = sizeof(A)/sizeof(A[0]);
    
    Create_LinkedList(A,n);
    Display_LinkedList(first);
    
    printf("\nNo. of nodes : %d ", Count_Nodes(first));
    printf("\nSum of nodes : %d ", Sum_Nodes(first));
    printf("\nMax Element : %d ", Max_Element(first));
    printf("\nSearch key : %u \n", LinearSearch_LinkedList(first, 11));
    
    Insert(first,3,11); Insert(first,-4,12); Insert(first,5,17); 
    Insert_SortedLinkedList(first,16); Insert_SortedLinkedList(first,16);
    Display_LinkedList(first);
    
    Delete(first,3);
    Display_LinkedList(first);
    
    printf("Is the list sorted ? : %d ", IsSorted(first));
    
    Remove_Duplicates(first);
    Display_LinkedList(first);
    
    Reverse_LinkedList(first);
    Display_LinkedList(first);
    
    Reverse_LinkedList_Array(first);
    Display_LinkedList(first);
    
    second = first;
    int B[] = {21,25,26,35,37}; n = sizeof(B)/sizeof(B[0]); // first is head ptr
    Create_LinkedList(B,n);
    Display_LinkedList(first);
    
    Concat_LinkedList(second,first);
    Display_LinkedList(first);
    
    second = first;
    int C[] = {33,34,51,53,58}; n = sizeof(C)/sizeof(C[0]); // first is head ptr
    Create_LinkedList(C,n);
    Display_LinkedList(first);
    
    Merge_LinkedList(second,first);
    Display_LinkedList(first);
    
    printf("\nIs there a Loop : %d ", IsLoop_LinkedList(first));


    return 0;
}
