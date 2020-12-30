#include <stdio.h> //--------------------------------Toeplitz Matrix -Maps as -- 1st Row Elements| 1st Column elements
#include<stdlib.h>

// NZ Elements = 2n-1 



struct Toeplitz_Matrix
{
    int* A;
    int n;
};

int Index_Map(int i,int j, int n)//--------------1st Row | 1st Column
{
    if(i<=j) return (j-i);  
    else if(i>j) return (n+i-j-1);
}

void Set(struct Toeplitz_Matrix* M, int i, int j, int x)
{
    if(i==1 || j== 1) M->A[Index_Map(i,j,M->n)] = x;
}

int Get(struct Toeplitz_Matrix M, int i, int j)
{
    return M.A[Index_Map(i-1,j-1,M.n)];
}

void Display(struct Toeplitz_Matrix M)
{
    for(int i=1; i<=M.n; i++)
    {
        for(int j=1; j<=M.n; j++)
        {
            printf(" %d", M.A[Index_Map(i,j,M.n)]);
        }
        printf("\n");
    }
}

int main()
{
    struct Toeplitz_Matrix M; M.n =5; //size
    
    M.A = (int*)malloc((2 * M.n - 1) * sizeof(int)); // store only 1st row & column elements
    
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
