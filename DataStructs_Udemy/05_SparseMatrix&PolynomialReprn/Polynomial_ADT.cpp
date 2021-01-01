#include<iostream>
using namespace std;

class Term
{
public:
    int coeff; int expt;
};

class Poly
{
private:
    int n; 
    Term *term;
    
public:
    Poly(int n=0)
    {
        this->n = n;
        term = new Term[n];
    }
    ~Poly() { delete []term;}
    
    void Create()
    {
        cout<<"Enter terms: "<<endl;
        for(int i=0; i<n;i++)
        {
            cin>>term[i].coeff>>term[i].expt;
        }
    }
    
    void Display()
    {
        cout<<"Polynomial : ";
        for(int i=0; i<n;i++)
        {
            cout<<term[i].coeff<<" X^"<<term[i].expt<<" + ";
        }
        cout<<0<<endl;
    }
    
    Poly* Add(Poly *P2)
    {
        Poly* sum = new Poly;
        sum->term = new Term[n+P2->n];
        
        int k=0,i=0,j=0;
        while(i<n && j<P2->n)
        {
            if(term[i].expt > P2->term[j].expt)
                sum->term[k++] = term[i++];
            else if(term[i].expt < P2->term[j].expt)
                sum->term[k++] = P2->term[j++];
            else
            {
                sum->term[k].expt = term[i].expt;
                sum->term[k++].coeff = term[i++].coeff+P2->term[j++].coeff;
            }
        }
        for(;i<n;i++) sum->term[k++] = term[i];
        for(;j<P2->n;j++) sum->term[k++] = P2->term[j];
        
        sum->n = k;
        return sum;
    }
    
};



int main()
{
    Poly P(3),A(3), B(6);
    P.Create();
    P.Display();
    
    A.Create();
    A.Display();
    
    B= *(P.Add(&A));
    
    B.Display();

    return 0;
}
