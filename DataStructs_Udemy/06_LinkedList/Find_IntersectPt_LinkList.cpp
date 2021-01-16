#include<iostream>
#include<stack>

using namespace std;

//-------------------------Find Intersection Point ---------------------------//
struct Node
{
    int data;
    struct Node *next;
} *first= NULL, *second =NULL;


void Create_LinkList(int A[], int n)  // Create
{
    first =(struct Node*)malloc(sizeof(struct Node));
    first->data = A[0]; first->next = NULL;
    
    struct Node *last = first;
    
    for(int i=1; i<n; i++)
    {
        struct Node *t =(struct Node*)malloc(sizeof(struct Node));
        t->data = A[i]; t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Create_LinkList_Intersected(int A[], int n, struct Node *p)  // Create
{
    second =(struct Node*)malloc(sizeof(struct Node));
    second->data = A[0]; second->next = NULL;
    
    struct Node *last = second;
    
    for(int i=1; i<n; i++)
    {
        struct Node *t =(struct Node*)malloc(sizeof(struct Node));
        t->data = A[i]; t->next = NULL;
        last->next = t;
        last = t;
    }
    last->next = p;
}
void Display_LinkList(struct Node *p) // Display
{
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

void Find_Intersection_Point(struct Node *p, struct Node *q) //----------------------------------------Find Intersection Point
{
    stack<struct Node*> stk1,stk2;
    while(p)
    {
        stk1.push(p);
        p=p->next;
    }
    while(q)
    {
        stk2.push(q);
        q=q->next;
    }
    struct Node *meet_pt;
    while(stk1.top() == stk2.top()) 
    {
        meet_pt = stk1.top();
        stk1.pop();
        stk2.pop();
    }
    
    cout<<"METHOD 1: A & B Intersect at address "<<meet_pt<<" and value "<<meet_pt->data<<endl;
}

int Count_Nodes(struct Node *p)
{
    int count=0;
    while(p)
    {
        p=p->next;
        count++;
    }
    return count;
}

void Find_Intersection_Point_2(struct Node *p, struct Node *q) //----------------------------------------Find Intersection Point----Simpler (No extra memory needed)
{
    int a= Count_Nodes(p);
    int b= Count_Nodes(q);
    
    while(a<b) //decrement b until a==b
    {
        q=q->next;
        b--;
    }
    while(a>b) //decrement a until a==b
    {
        p=p->next;
        a--;
    }
    while(p) // a==b
    {
        if(p==q)
        {
            cout<<"METHOD 2: A & B Intersect at address "<<p<<" and value "<<p->data<<endl;
            return;
        }
        p=p->next;
        q=q->next;
    }
    
}

int main()
{
    int A[] = {1,2,3,4,5,11,12,13,14}; int n= sizeof(A)/sizeof(A[0]);
    Create_LinkList(A,n);
    Display_LinkList(first);
    
    int i = 4; 
    struct Node *p= first;
    while(i>0)
    {
        p=p->next;
        i--;
    }
    
    printf("Intersection point : %d \n", p->data);
    
    int B[] = {27,55,66,99};  n= sizeof(B)/sizeof(B[0]);
    Create_LinkList_Intersected(B,n,p);
    Display_LinkList(second); 
    
    Find_Intersection_Point(first,second);
    
    Find_Intersection_Point_2(first,second);
    
    return 0;
}
