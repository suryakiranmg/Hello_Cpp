//xxxxxxxxxxxxxx-------Incorrect Code---------------xxxxx//


#include<iostream>
using namespace std;

class Term
{
public:
    int coeff; int exp;
};
class Poly
{
private:
    int n; Term *t;
public:
    Poly(int n)
    {
        this->n = n;
        t = new Term[n];
    }
    ~Poly() { delete []t;}
    void Create()
    {
        cout<<"Enter terms: "<<endl;
        for(int i=0; i<n;i++)
        {
            cin>>t[i].coeff>>t[i].exp;
        }
    }
    void Display()
    {
        for(int i=0; i<n;i++)
        {
            cout<<t[i].coeff<<"X"<<t[i].exp<<"+";
        }
        cout<<endl;
    }
    
    Poly* Add(Poly *p2)
    {
        
        Poly *sum = new Poly[n+p2->n];
        int k=0,i=0,j=0;
        while(i<n && j<p2->n)
        {
            if(t[i].exp > p2->t[j].exp)
                sum->t[k++] = t[i++];
            else if(t[i].exp < p2->t[j].exp)
                sum->t[k++] = p2->t[j++];
            else
            {
                sum->t[k++].exp = t[i].exp;
                sum->t[k++].coeff = t[i++].coeff+p2->t[j++].coeff;
            }
        }
        for(;i<n;i++) sum->t[k++] = t[i];
        for(;j<p2->n;j++) sum->t[k++] = p2->t[j];
        sum->n = k;
        return sum;
    }
    
};



int main()
{
    Poly p(3);
    p.Create();
    p.Display();
    

    return 0;
}
