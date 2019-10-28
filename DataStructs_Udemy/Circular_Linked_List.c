
#include<stdlib.h>
#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *Head;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    //1st node
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    //remaining nodes
    for(i=1;i<n;i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *h)
{
    do
    {
        printf(" %d", h->data);
        h=h->next;
    } while(h!=Head);
    printf("\n");
}

int Length(struct Node *p)
{
    int len=0;
    do
    {
        len++;
        p=p->next;
    } 
    while(p!=Head);
    return len;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index<0 || index > Length(Head)) return;
    //insert at 1st position
    if(index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if(Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            while(p->next != Head) p= p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else//inserting in b/n
    {
        for(i=0;i <index-1;i++) p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int i,x;
    if(index<0 || index>Length(Head)) return -1;
    //Head node
    if(index ==1)
    {
        while(p->next != Head) p=p->next;
        x = Head->data;
        if(Head == p)
        {
            free(Head); Head = NULL;
        }
        else 
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else //delete in between
    {
        for(i=0;i<index-2;i++) p = p->next;
        q = p->next;
        p->next = q->next;
        x= q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[] = {2,3,4,5,6};
    Create(A,5);
    
    Delete(Head,8);
    Display(Head);
    return 0;
}
