#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
    private:
    Node *first;
    public:
    LinkedList() {first = NULL;}
    LinkedList(int A[], int n);
    ~LinkedList();
    
    void Display(); //-------------------------------Display
    void Insert(int index, int x); //----------------Insert at an index
    int Delete(int index); //------------------------Insert from index
    int Length();  //--------------------------------Length of Linked List
};

LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t; 
    first = new Node; first->data = A[0]; first->next = NULL;
    last = first;
    for(int i=1;i<n;i++)
    {
        t= new Node; t->data = A[i]; t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = first;
    while(first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display()
{
    Node *p = first;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int LinkedList::Length()
{
    Node *p = first;
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

void LinkedList::Insert(int index, int x)
{
    Node *p = first, *t;
    if(index <0 || index > Length()) return;
    t = new Node; t->data = x; t->next= NULL;
    if(index ==0)
    { 
        t->next= first;
        first = t;
    }
    else
    {
        for(int i=0;i<index-1;i++) p=p->next;
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::Delete(int index)
{
    Node *p, *q = NULL;
    int x = -1;
    if(index <1 || index > Length()) return -1;
    if(index == 1)
    {
        p = first;
        x = p->data;
        first = first->next;
        delete p;
    }
    else
    {
        p = first;
        for(int i=0; i<index-1;i++)
        {
            q = p;
            p= p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;   
}


int main()
{
    int A[] = {1,2,3,4,5,6};
    LinkedList L(A,5);
    cout<<"Deleted : "<<L.Delete(3)<<endl;
    cout<<"Length : "<<L.Length()<<endl;
    L.Display();
    L.Insert(0,10);
    L.Insert(3,15);
    L.Display();
 
    return 0;
}
