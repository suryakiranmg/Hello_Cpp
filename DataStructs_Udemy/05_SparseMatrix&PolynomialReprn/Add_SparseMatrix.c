#include<stdio.h>
#include<stdlib.h>

struct Matrix_Element
{
    int i; int j; int val;
};

struct Sparse_Matrix
{
    int m; //rows
    int n; //columns
    int num; // # NZ elements
    struct Matrix_Element* ele;
};

void Create_Sparse(struct Sparse_Matrix *M)
{
    printf("Enter Dimensions (m,n): "); scanf("%d %d", &M->m, &M->n);
    printf("\nEnter # NZ Elements : "); scanf("%d", &M->num);
    
    M->ele = (struct Matrix_Element*)malloc(M->num * sizeof(struct Matrix_Element));
    
    printf("\nEnter all elements(i,j,value): ");
    
    for(int i=0; i< M->num; i++)
    {
        scanf("%d %d %d", &M->ele[i].i, &M->ele[i].j, &M->ele[i].val);
    }
}

void Display_Sparse(struct Sparse_Matrix M)
{
    int k=0;
    for(int i=1; i<=M.m; i++)
    {
        for(int j=1; j<=M.n; j++)
        {
            if(i==M.ele[k].i && j==M.ele[k].j)
            {
                printf(" %d", M.ele[k++].val);
            }
            else printf(" 0");
        }
        printf("\n");
    }
}

struct Sparse_Matrix* Add_Sparse(struct Sparse_Matrix A, struct Sparse_Matrix B)
{
   struct Sparse_Matrix* Sum;
   Sum = (struct Sparse_Matrix*)malloc(sizeof(struct Sparse_Matrix));
   Sum->ele = (struct Matrix_Element*)malloc(sizeof(struct Matrix_Element)*(A.num + B.num));
   
   int x=0, y=0,k=0;
   while(x<A.num && y<B.num)
   {
       if((A.ele[x].i == B.ele[y].i) && (A.ele[x].j == B.ele[y].j)) // Both equal
       {
           Sum->ele[k].i = A.ele[x].i; Sum->ele[k].j = A.ele[x].j;
           Sum->ele[k++].val = A.ele[x++].val + B.ele[y++].val;
       }
       else if(A.ele[x].i < B.ele[y].i) // A's row first
       {
           Sum->ele[k++] = A.ele[x++];
       }
       else if(A.ele[x].i > B.ele[y].i) // B's row first
       {
           Sum->ele[k++] = B.ele[y++];
       }
       else if((A.ele[x].i == B.ele[y].i) && (A.ele[x].j < B.ele[y].j)) // rows equal, A's column
       {
           Sum->ele[k++] = A.ele[x++];
       }
       else if((A.ele[x].i == B.ele[y].i) && (A.ele[x].j > B.ele[y].j)) // rows equal, B's column
       {
           Sum->ele[k++] = B.ele[y++];
       }
   }
   // Copy the rest
   while(x < A.num)   { Sum->ele[k++] = A.ele[x++]; }
   while(y < B.num)   { Sum->ele[k++] = B.ele[y++]; }
   
   Sum->m = A.m; Sum->n = A.n; Sum->num = k;
   return Sum;
}

int main()
{
    struct Sparse_Matrix A, B, *C;
    Create_Sparse(&A); Create_Sparse(&B);
    
    printf("Sparse Matrix A: \n"); Display_Sparse(A);
    printf("Sparse Matrix B: \n"); Display_Sparse(B);
    
    C= Add_Sparse(A,B);
    
    printf("Sparse Sum Matrix C: \n"); Display_Sparse(*C);

    return 0;
}
