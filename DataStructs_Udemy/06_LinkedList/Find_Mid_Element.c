#include<stdio.h>
#include<stdlib.h>

//---------Find the Middle Element ----(use 2 ptrs: one moves 1 step & other 2 step each)

struct Node
{
    int data;
    struct Node *next;
} *head= NULL;

void Create_LinkList(int A[], int n)
{
    head =(struct Node*)malloc(sizeof(struct Node));
    head->data = A[0]; head->next = NULL;
    
    struct Node *last = head;
    
    for(int i=1; i<n; i++)
    {
        struct Node *t =(struct Node*)malloc(sizeof(struct Node));
        t->data = A[i]; t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display_LinkList(struct Node *p)
{
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

void Find_Mid_Element(struct Node *p) //----------------------------------------Find the Middle Element
{
    struct Node *q=p;
    while(p)
    {
        p=p->next; 
        if(p) p=p->next;
        if(p) q=q->next;
    }
    printf("\n %d is the Middle Element", q->data);
}

int main()
{
    int A[] = {1,2,3,4,5,11,12,13,14}; int n= sizeof(A)/sizeof(A[0]);
    
    Create_LinkList(A,n);
    Display_LinkList(head);
    
    Find_Mid_Element(head);
    
    return 0;
}
