#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
} *head = NULL; // global head ptrs

void Create_CircularLinkList(int A[], int n) //---------------------------------Create Circular Linked List
{
    struct Node *t, *last;
    //head node    
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0]; head->next = head; //link to itself
    
    last = head;
    
    for(int i=1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;

        
        last->next = t;
        last = t;
    }
}

void Display_CircularLinkList(struct Node *p) //--------------------------------Display Circular Linked List
{
    do
    {
        printf("%d ",p->data);
        p=p->next;
    } while(p != head);
    printf("\n");
}

int Count_Nodes(struct Node* p) //----------------------------------------------Count Nodes
{
    if(p==NULL) return 0;
    int count=1;
    while(p->next != head)
    {
        p=p->next;
        count++;
    }
    return count;
}

void Insert_CircularLinkList(struct Node* p,int index, int data) //-------------Insert at index
{
    if(index < 0 || index > Count_Nodes(head)) return;
    
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data = data;
    
    if(index == 0) // insert at head
    {
        if(head == NULL) //empty list
        {
            head = t;
            head->next = head;
        }
        else
        {
            while(p->next != head) p=p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else // insert at index > 0
    {
        for(int i=0; i<index-1; i++) p= p->next;
        t->next = p->next;
        p->next = t;
    }
}

int Delete_CircularLinkList(struct Node* p, int index) //-----------------------Delete from index
{
    if(index < 0 || index >= Count_Nodes(head)) return -1;
    
    int x;
    if(index == 0) // delete head
    {
        while(p->next != head) p=p->next;
        x=head->data;
        if(head == p) //only one Node
        {
            free(head); head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else // delete any other node
    {
        for(int i=0; i<index-1; i++) p=p->next;
        struct Node* q=p->next;
        p->next = q->next;
        x= q->data;
        free(q);
    }
    return x;
}


int main()
{
    int A[] = {4,5,7,8,11,13,19}, n= sizeof(A)/sizeof(A[0]);
    Create_CircularLinkList(A,n);
    Display_CircularLinkList(head);
    
    Insert_CircularLinkList(head,0,3);
    Display_CircularLinkList(head);
    
    Delete_CircularLinkList(head,0);
    Display_CircularLinkList(head);

    return 0;
}
