#include <iostream>
#include<math.h>
using namespace std;

struct Node
{
    int coeff;
    int expt;
    struct Node* next;
} *poly_head = NULL,*first_h = NULL, *second_h= NULL, *sum_h= NULL;

void Create_Poly()
{
    int n;
    struct Node *last;
    poly_head = NULL;
    cout<<"Enter # terms : "; cin>>n;
    cout<<endl<<"Enter each term (coeff,expt) in descending order of powers : ";
    for(int i=0; i<n; i++)
    {
        struct Node *t = (struct Node*)malloc(sizeof(struct Node));
        cin>>t->coeff; cin>>t->expt;t->next = NULL;
        
        if(poly_head == NULL) 
        {
          poly_head = t;  
          last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *p)
{
    while(p)
    {
        cout<<p->coeff<<" x^"<<p->expt<<" + ";
        p=p->next;
    }
    cout<<0<<endl;
}

int Evaluate(struct Node *p, int x)
{
    int sum = 0;
    while(p)
    {
        sum += p->coeff * pow(x, p->expt);
        p=p->next;
    }
    return sum;
}

struct Node* Add_Poly(struct Node *p, struct Node *q)
{
    struct Node *last;
    while(p && q)
    {
        struct Node *t = (struct Node*)malloc(sizeof(struct Node));
        t->next = NULL;
        if(p->expt == q->expt)
        {
            t->coeff = p->coeff + q->coeff;
            t->expt  = p->expt;
            p=p->next; q=q->next;
        }
        else if(p->expt > q->expt)
        {
            t=p;
            p=p->next;
            t->next  = NULL;
        }
        else if(p->expt < q->expt)
        {
            t=q; 
            q=q->next;
            t->next = NULL;
        }
        
        if(sum_h == NULL) 
        {
            sum_h = t;  
            last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
    return sum_h;
}

int main()
{
    
    Create_Poly(); first_h = poly_head;
    Display(first_h);
    //cout<<"Polynomial Evaluated : "<<Evaluate(first_h,3)<<endl;
    
    Create_Poly(); second_h = poly_head;
    Display(second_h);
    
    
    Add_Poly(first_h, second_h);
    cout<<endl<<"Sum Polynomial : ";
    Display(sum_h);

    return 0;
}
