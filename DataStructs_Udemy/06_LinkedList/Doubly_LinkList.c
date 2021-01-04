#include <stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
} *head = NULL; // global head ptrs

int Count_Nodes(struct Node* p) //----------------------------------------------Count Nodes
{
    int count=0;
    while(p != NULL)
    {
        p=p->next;
        count++;
    }
    return count;
}

void Insert_DoublyLinkList(struct Node* p, int index, int value) //-------------Insert Node
{
    if(index<0 || index > Count_Nodes(p)) return;
    
    struct Node* t= (struct Node*)malloc(sizeof(struct Node)); t->data = value;
    
    if(index==0) // insert at head
    {
        if(head == NULL) // list empty
        {
            head = t;
            head->prev = NULL; head->next =NULL;
        }
        else
        {
            t->prev = NULL; t->next = head;
            head->prev = t;
            head = t;
        }
    }
    else
    {
        for(int i=0; i<index-1; i++) p=p->next; //go to index-1
        
        t->next = p->next; 
        if(p->next) p->next->prev = t;
        t->prev = p; 
        p->next =t;
    }
}

int Delete_DoublyLinkList(struct Node* p, int index) //-------------------------Delete Node
{
    if(index<0 || index >= Count_Nodes(head)) return -1;
    if(p==NULL) return -1;
    
    int x;
    if(index==0)
    {
        x=head->data;
        head= head->next;
        if(head) head->prev = NULL;
        free(p);
    }
    else
    {
        for(int i=0; i<index; i++) p=p->next;
        x=p->data;
        
        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        free(p);
    }
    return x;
}

void Display_DoublyLinkList(struct Node* p) //----------------------------------Display Doubly Link List
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

void Reverse_DoublyLinkList(struct Node* p) //----------------------------------Reverse Link List
{
    struct Node *temp;
    
    while(p)
    {
        // swap prev & next
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
       
        p=p->prev;  // move to next
        if(p && p->next == NULL) head = p; //last node as head
    }
}

int main()
{
    Insert_DoublyLinkList(head,0,3);
    Display_DoublyLinkList(head);
    
    Insert_DoublyLinkList(head,1,6); Insert_DoublyLinkList(head,2,9); Insert_DoublyLinkList(head,3,12);
    Insert_DoublyLinkList(head,1,5); Insert_DoublyLinkList(head,3,8); Insert_DoublyLinkList(head,5,10);
    Display_DoublyLinkList(head);
    
    Delete_DoublyLinkList(head,0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    Display_DoublyLinkList(head);
    
    Reverse_DoublyLinkList(head);
    Display_DoublyLinkList(head);


    return 0;
}
