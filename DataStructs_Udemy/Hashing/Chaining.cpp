
#include <iostream>
using namespace std;

class Node      //Linked List Node
{
    public:
        int data;
        Node* next;
};

class HashTable     // Hash Table
{
    public:
        Node** HT;   //Double pointer for hash table
        HashTable(); // constructor
        int hash(int key);
        void Insert(int key);
        int Search(int key);
        ~HashTable();
};

HashTable::HashTable()
{
    HT = new Node* [10];
    for(int i=0 ;i<10; i++) HT[i]=nullptr;
}

HashTable::~HashTable()
{
    for(int i=0;i<10;i++)
    {
        Node* p= HT[i];
        while(HT[i])
        {
            HT[i]=HT[i]->next; delete p; p=HT[i];
        }
    }
    delete[] HT;
}

int HashTable::hash(int key)
{
    return key%10;
}

void HashTable::Insert(int key)
{
    Node* t = new Node; t->data = key; t->next = nullptr;
    int HT_index = hash(key);
    
    if(HT[HT_index]==nullptr) HT[HT_index]=t;//no nodes
    else 
    {
        Node* p = HT[HT_index];
        Node* q = HT[HT_index];
        while(p && p->data<key)//Traverse to find insert position
        {
            q=p; p=p->next;
        }
        
        if(q==HT[HT_index]) //insert at root
        {
            t->next = HT[HT_index];
            HT[HT_index] = t;
        }
        else
        {
           t->next = q->next; q->next =t; 
        }
    }
}

int HashTable::Search(int key)
{
    int HT_index = hash(key);
    Node* p = HT[HT_index];
    while(p)
    {
        if(p->data == key) return p->data;
        p=p->next;
    }
    return -1;
}

int main()
{
    int A[] = {16,12,25,39,16,122,5,68,75};
    int n = sizeof(A)/sizeof(A[0]);
    
    HashTable H;  //Create Hash table
    for(int i=0; i<n; i++) H.Insert(A[i]); 
    
    int key =122;
    if(H.Search(key) ==-1) cout<<"Key not found"<<endl;
    else cout<<key<<" Found"<<endl;
    
    
    return 0;
}
