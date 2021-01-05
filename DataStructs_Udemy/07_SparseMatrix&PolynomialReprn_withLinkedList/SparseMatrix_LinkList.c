//----------------------Sparse Matrix using Linked List
#include<iostream>
using namespace std;

struct Node
{
    int column;
    int value;
    struct Node *next;
};

struct Node** Create_SparseMatrix(int m, int n)
{
    cout<<endl<<"Enter all elements: ";
    int temp=0;
    struct Node **A = (struct Node**)malloc(m*sizeof(struct Node*)); // double pointer -- pointer matrix 
    struct Node *last, *t;
    
    for(int i=0; i<m; i++)
    {
        A[i] = NULL;
        for(int j=0; j<n; j++)
        {
            cin>>temp; 
            if(temp != 0)
            {
                // create node
                t = (struct Node*)malloc(sizeof(struct Node));
                t->column = j; t->value = temp; t->next = NULL;
                
                // link to row pointer
                if(A[i]==NULL)
                {
                    A[i] = t;
                    last = t;
                }
                else
                {
                    last->next = t;
                    last = t;
                }
            }
        }
    }
    
    return A;
}

void Display_SparseMatrix(struct Node **A, int m, int n)
{
    cout<<endl<<"Sparse Matrix "<<endl;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(A[i] && j==A[i]->column)
            {
                cout<<" "<<A[i]->value;
                A[i]=A[i]->next;
            }
            else 
            {
                cout<<" 0";
            }
        }
        cout<<endl;
    }
}

struct Node** Add_SparseMatrix (struct Node** A, struct Node** B, int m, int n)
{
    struct Node **C = (struct Node**)malloc(m * sizeof(struct Node*)); // sum matrix
    struct Node *last,*t;
    
    for(int i=0; i<m; i++)
    {
        C[i] = NULL;
        while(A[i] || B[i])
        {
            // create node
            t = (struct Node*)malloc(sizeof(struct Node));
            t->next = NULL;
            
            if( A[i] && B[i] )
            {
                if(A[i]->column == B[i]->column) // Aij+Bij
                {
                    t->value  = A[i]->value + B[i]->value;
                    t->column = A[i]->column; 
                    A[i]= A[i]->next; 
                    B[i]= B[i]->next;
                }
                else if( A[i]->column < B[i]->column ) // Aij
                {
                    t->value  = A[i]->value; 
                    t->column = A[i]->column; 
                    A[i]= A[i]->next;
                }
                else // Bij
                {
                    t->value  = B[i]->value; 
                    t->column = B[i]->column; 
                    B[i]= B[i]->next;
                }
            }
            else if( A[i] && !B[i] ) // Aij
            {
                t->value  = A[i]->value; 
                t->column = A[i]->column; 
                A[i]= A[i]->next;
            }
            else if( !A[i] && B[i] ) // Bij
            {
                t->value  = B[i]->value; 
                t->column = B[i]->column; 
                B[i]= B[i]->next;
            }
            
            // Link to C[i]
            if(C[i]==NULL)
            {
                C[i] = t;
                last = t;
            }
            else
            {
                last->next = t;
                last = t;
            }
        }
    }
    return C;
}

int main()
{
    int m, n;
    cout<<"Enter # rows (m): "; cin>>m;
    cout<<endl<<"Enter # columns (n): "; cin>>n;
    
    struct Node **A = Create_SparseMatrix(m,n); // A
    //Display_SparseMatrix(A,m,n);
    
    struct Node **B = Create_SparseMatrix(m,n); // B
    //Display_SparseMatrix(B,m,n);
    
    struct Node **C = Add_SparseMatrix(A,B,m,n); // C = A + B
    Display_SparseMatrix(C,m,n);
    
    return 0;
}

