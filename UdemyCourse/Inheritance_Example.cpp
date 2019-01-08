
#include<iostream>
using namespace std;
//Parent Class
class Employee
{
  private:
      int eid;
      string name;
  public:
      Employee(int e, string n)
        {
         eid = e;
         name = n;
        }
      int getEmployeeID() {return eid;}
      string getName() {return name;}
};

//Child classes
class FullTimeEmployee : public Employee
{
   private:
     int salary;
   public:
     FullTimeEmployee(int e, string n, int sal): Employee(e,n)
     {
      salary = sal; 
     }
     int getSalary() {return salary;}
};

class PartTimeEmployee : public Employee
{
   private:
     int wage;
   public:
     PartTimeEmployee(int e, string n, int w): Employee(e,n)
     {
      wage = w; 
     }
     int getWage() {return wage;}
};

//main function
int main()
{
 PartTimeEmployee p1(1,"Suki",2000);
 FullTimeEmployee p2(2,"Tom",3000);
 cout<<"Salary of "<<p2.getName()<<" is: "<<p2.getSalary()<<endl;
 cout<<"Daily wage of "<<p1.getName()<<" is: "<<p1.getWage()<<endl;
}
