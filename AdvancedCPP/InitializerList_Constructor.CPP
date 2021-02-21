#include <iostream>
#include<string>
using namespace std;

class Account
{
    private:
        int id;
        std::string name;
        double balance;
        const int PIN=1234;
    public:
        Account ():id(1002),name("abcd"),balance(1000)
        {
            cout<<"Account-default : "<<id<<","<<name<<","<<balance<<","<<PIN<<endl;
        }
        Account (int x, string str, double y, int z):id(x),name(str),balance(y),PIN(z)
        {
            cout<<"Account-parameterized : "<<id<<","<<name<<","<<balance<<","<<PIN<<endl;
        }
        Account (const Account &ref):id(ref.id),name(ref.name),balance(ref.balance),PIN(ref.PIN)
        {
            cout<<"Account-copyconstruct : "<<id<<","<<name<<","<<balance<<","<<PIN<<endl;
        }
        void Credit (double amt)
        {
            balance += amt;
        }
        void Debit (double amt)
        {
            balance -= amt;
        }
        double GetBalance()
        {
            return balance;
        }
        void display()
        {
            cout<<"Account-display : "<<id<<","<<name<<","<<balance<<","<<PIN<<endl;
        }
};

int main()
{
    Account a1(1001,"abcd",5000.0,4343); a1.display();
    Account a2; a2.display();
    Account a3(a2); a3.display();
    return 0;
}
