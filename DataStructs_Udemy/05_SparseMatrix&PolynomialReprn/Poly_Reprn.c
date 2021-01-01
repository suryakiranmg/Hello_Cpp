//-------------------------------------------------------Polynomial Representation-----//
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct Poly_Term
{
    int coeff;
    int expt;
};

struct Poly_Eqn
{
    int n;
    struct Poly_Term *term;
};

void Create_Poly(struct Poly_Eqn* P) //-------------------------------Create polynomial
{
    printf("Number of terms? "); scanf("%d",&P->n);
    P->term=(struct Poly_Term*)malloc(P->n*sizeof(struct Poly_Term));
    
    printf("Enter terms(coeff, expt): \n");
    for(int i=0; i<P->n; i++)
    {
        scanf("%d %d",&P->term[i].coeff,&P->term[i].expt);
        
    }
    
}

void Display_Poly(struct Poly_Eqn P) //-------------------------------Display polynomial
{
    printf("Polynomial : ");
    for(int i=0;i<P.n;i++)
    {
        printf("%d x^%d +",P.term[i].coeff,P.term[i].expt);
    }
    printf(" 0\n");
}

int Poly_Evaluate(struct Poly_Eqn P, int x) //------------------------Evaluate Polynomial at x
{
    int sum=0;
    for(int i=0; i<P.n; i++)
    {
        sum += P.term[i].coeff * pow(x,P.term[i].expt) ;
    }
    return sum;
}

struct Poly_Eqn* Add_Poly(struct Poly_Eqn P1,struct Poly_Eqn P2) //---Add polynomials
{
    struct Poly_Eqn *sum;
    sum=(struct Poly_Eqn*)malloc(sizeof(struct Poly_Eqn));
    sum->term=(struct Poly_Term*)malloc((P1.n+P2.n)*sizeof(struct Poly_Term));
    
    int i=0,j=0,k=0;
    while(i<P1.n && j<P2.n)
    {
        if(P1.term[i].expt > P2.term[j].expt)  sum->term[k++]=P1.term[i++];
        else if(P1.term[i].expt < P2.term[j].expt)  sum->term[k++]=P2.term[j++];
        else
        {
            sum->term[k].expt = P1.term[i].expt;
            sum->term[k++].coeff=P1.term[i++].coeff + P2.term[j++].coeff;
        }
        
    }
    // copy remaining
    for(;i<P1.n;i++) sum->term[k++]=P1.term[i];
    for(;j<P2.n;j++) sum->term[k++]=P2.term[j];
    
    sum->n=k;
    return sum;
}


int main()
{
    struct Poly_Eqn P1,P2,*P3;
    
    Create_Poly(&P1);
    Create_Poly(&P2);
    
    P3=Add_Poly(P1,P2);
    
    printf("\n");
    Display_Poly(P1);
    Display_Poly(P2);
    Display_Poly(*P3);
    
    printf("\nPolynomial Evaluation: %d", Poly_Evaluate(*P3,1));
    return 0;
}
