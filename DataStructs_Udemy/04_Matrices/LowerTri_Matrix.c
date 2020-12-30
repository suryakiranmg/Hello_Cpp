#include <stdio.h>//--------------------------------Lower Triangular Matrix - Row major Map/ Column Major Map
#include<stdlib.h>

// NZ Elements = n x (n+1)/ 2
// Row major Formula, Index (A[i][j]) = i(i-1)/ 2  +  (j-1)
// Column major Formula, Index (A[i][j]) = n(j-1) - (j-2)(j-1)/ 2 + (i-j)


struct LowerTri_Matrix
{
    int* A;
    int n;
};

int Index_Map(int i,int j, int n)//--------------Row Major/Column Major Map
{
    //------------ Row Major Map
    return (i*(i-1)/2 + (j-1));  
    //------------ Column Major Map
    //return (n*(j-1) - ((j-2)*(j-1)/2) + (i-j));
}

void Set(struct LowerTri_Matrix* M, int i, int j, int x)
{
    if(i>=j) M->A[Index_Map(i,j,M->n)] = x;
}

int Get(struct LowerTri_Matrix M, int i, int j)
{
    if(i>=j) return M.A[Index_Map(i-1,j-1,M.n)];
    else return 0;
}

void Display(struct LowerTri_Matrix M)
{
    for(int i=1; i<=M.n; i++)
    {
        for(int j=1; j<=M.n; j++)
        {
            if(i>=j) printf(" %d", M.A[Index_Map(i,j,M.n)]);
            else printf(" 0");
        }
        printf("\n");
    }
}

int main()
{
    struct LowerTri_Matrix M; M.n =3; //size
    
    M.A = (int*)malloc((M.n*(M.n+1)/2) * sizeof(int));
    
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
    
    
    //printf("%d\n",Get(M,1,1));
    
    Display(M);

    return 0;
}
