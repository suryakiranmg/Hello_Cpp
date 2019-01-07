#include<iostream>
using namespace std;

//Class Definition
class Rational
{
private:
    int p;
    int q;
    
public:
    //constructors
    Rational(int p = 1, int q=1)
    {
        this->p = p;
        this->q = q;
    }
    Rational(Rational &r)
    {
        this->p = r.p;
        this->q = r.q;
    }
    //Accessors & Mutators
    int getP() {return p;}
    int getQ() {return q;}
    void setP(int p) {this->p = p;}
    void setQ(int q) {this->q = q;}
    //Facilitators
    Rational operator+(Rational r)
    {
        Rational temp;
        temp.p = this->p*r.q + r.p * this->q;
        temp.q = this->q*r.q;
        return temp;
    }
    friend ostream & operator<<(ostream &out, Rational &r);
};

//Friend Definition
ostream & operator<<(ostream &out, Rational &r)
{
    out<<r.p<<"/"<<r.q;
    return out; 
}

//Main Function
int main()
{
    Rational r1(3,4), r2(2,5), r3;
    r3 = r1 + r2;
    cout<<"Sum of "<<r1<<" and "<<r2<<" is: "<<r3<<endl;
}

