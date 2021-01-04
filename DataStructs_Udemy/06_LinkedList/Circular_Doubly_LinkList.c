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
    if(p==NULL) return 0;
    
    int count=0;
    do
    {
        p=p->next;
        count++;
    }while(p != head);
    return count;
}

void Insert_CircularDoublyLinkList(struct Node* p, int index, int value) //-----Insert Node
{
    if(index<0 || index > Count_Nodes(p)) return;
    
    struct Node* t= (struct Node*)malloc(sizeof(struct Node)); t->data = value;
    
    if(index==0) // insert at head
    {
        if(head == NULL) // list empty
        {
            head = t;
            head->prev = head; head->next =head;
        }
        else
        {
            t->prev = head->prev; t->next = head;
            head->prev->next = t;
            head->prev = t;
            head = t;
        }
    }
    else
    {
        for(int i=0; i<index-1; i++) p=p->next; //go to index-1
        
        t->next = p->next; 
        p->next->prev = t;
        t->prev = p; 
        p->next =t;
    }
}

int Delete_CircularDoublyLinkList(struct Node* p, int index) //-----------------Delete Node
{
    if(index<0 || index >= Count_Nodes(head)) return -1;
    if(p==NULL) return -1;
    
    int x;
    if(index==0)
    {
        x=head->data;
        head->next->prev = head->prev;
        head->prev->next = head->next;
        
        head= head->next;
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

void Display_CircularDoublyLinkList(struct Node* p) //--------------------------Display Circular Doubly Link List
{
    do
    {
        printf("%d ", p->data);
        p=p->next;
    }while (p != head);
    printf("\n");
}


int main()
{
    Insert_CircularDoublyLinkList(head,0,3);
    Display_CircularDoublyLinkList(head);
    
    Insert_CircularDoublyLinkList(head,1,6); Insert_CircularDoublyLinkList(head,2,9); Insert_CircularDoublyLinkList(head,3,12);
    Display_CircularDoublyLinkList(head);
    Insert_CircularDoublyLinkList(head,1,5); Insert_CircularDoublyLinkList(head,3,8); Insert_CircularDoublyLinkList(head,5,10);
    Display_CircularDoublyLinkList(head);
    
    Delete_CircularDoublyLinkList(head,0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    Display_CircularDoublyLinkList(head);

    return 0;
}
