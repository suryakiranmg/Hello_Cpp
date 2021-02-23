#include<iostream>
using namespace std;

class Digit
{
    private:
        int m_digit;
    public:
        Digit (int d=0) : m_digit(d) //Constructor
         {}
        // Operator Overloading
        Digit& operator++ (); //prefix
        Digit& operator-- (); //prefix
        Digit operator++ (int); //postfix
        Digit operator-- (int); //postfix
        
        friend ostream& operator<< (ostream& out, const Digit d); 
};

Digit& Digit::operator++ ()
{
    if(m_digit==9) m_digit=0;
    else ++m_digit;
    return *this;
}

Digit& Digit::operator-- ()
{
    if(m_digit==0) m_digit=9;
    else --m_digit;
    return *this;
}

Digit Digit::operator++ (int)
{
    Digit temp(m_digit); //temp var with current val
    if(m_digit == 9) m_digit=0;
    else ++m_digit;
    return temp; 
}

Digit Digit::operator-- (int)
{
    Digit temp(m_digit); //temp var with current val
    if(m_digit == 0) m_digit=9;
    else --m_digit;
    return temp; 
}

ostream& operator<< (ostream& out, const Digit d)
{
    out<<d.m_digit;
    return out;
}

int main()
{
    Digit digit(5);
    
    cout<<digit<<endl;
    
    cout<<++digit<<endl; //pre
    cout<<digit++<<endl; //post
    cout<<digit<<endl;
    cout<<--digit<<endl; //pre
    cout<<digit--<<endl; //post
    
    cout<<digit<<endl;
    
    return 0;
}
