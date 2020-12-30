#include <stdio.h>

struct Diag_Matrix
{
    int* A;
    int n;
};

void Set(struct Diag_Matrix* M, int i, int j, int x)
{
    if(i==j) M->A[i] = x;
}

int Get(struct Diag_Matrix M, int i, int j)
{
    if(i==j) return M.A[i];
    else return 0;
}

void Display(struct Diag_Matrix M)
{
    for(int i=0; i<M.n; i++)
    {
        for(int j=0; j<M.n; j++)
        {
            if(i==j) printf(" %d", M.A[i]);
            else printf(" 0");
        }
        printf("\n");
    }
}

int main()
{
    struct Diag_Matrix M; M.n =3;
    Set(&M,0,0,9); Set(&M,1,1,11); Set(&M,2,2,13);
    printf("%d\n",Get(M,1,1));
    Display(M);

    return 0;
}
