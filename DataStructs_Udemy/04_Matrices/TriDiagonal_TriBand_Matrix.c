#include <stdio.h> //--------------------------------Symmetric Matrix -Maps as -- Lower Diagonal | Main Diagonal | Upper Diagonal
#include<stdlib.h>

// NZ Elements = 3n-2  



struct TriDiagonal_Matrix
{
    int* A;
    int n;
};

int Index_Map(int i,int j, int n)//--------------Lower Diag| Main Diag| Upper Diag
{
    if(i-j ==1) return (i-2);  
    else if(i-j ==0) return (n+i-2);
    else if(i-j ==-1) return (2*n +i -2);
}

void Set(struct TriDiagonal_Matrix* M, int i, int j, int x)
{
    if(abs(i-j)<=1) M->A[Index_Map(i,j,M->n)] = x;
}

int Get(struct TriDiagonal_Matrix M, int i, int j)
{
    if(abs(i-j)<=1) return M.A[Index_Map(i-1,j-1,M.n)];
    else return 0;
}

void Display(struct TriDiagonal_Matrix M)
{
    for(int i=1; i<=M.n; i++)
    {
        for(int j=1; j<=M.n; j++)
        {
            if(abs(i-j)<=1) printf(" %d", M.A[Index_Map(i,j,M.n)]);
            else printf(" 0");
        }
        printf("\n");
    }
}

int main()
{
    struct TriDiagonal_Matrix M; M.n =5; //size
    
    M.A = (int*)malloc((3 * M.n - 2) * sizeof(int)); // store only upper/lower triangular part
    
    printf("Enter the elments \n");
    int x;
    for(int i=1; i<=M.n; i++)
    {
        for(int j=1; j<=M.n; j++)
        {
            scanf("%d", &x);
            Set(&M,i,j,x); 
        }
    }
    
    // printf("%d\n",Get(M,1,1));
    
    Display(M);

    return 0;
}
