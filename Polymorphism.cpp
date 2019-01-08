#include<iostream>
using namespace std;

//Abstract Base Class
class Shape
{
 public:
  virtual float Area() = 0;
  virtual float Perimeter() = 0;
};

//Derived Classes
class Rectangle : public Shape
{
 private:
  float length;
  float breadth;
 public:
  //Constructor
  Rectangle(float l=1, float b=1) {length = l; breadth = b;}
  //Facilitators
  float Area() {return length*breadth;}
  float Perimeter() {return 2*(length+breadth);}
};

class Circle : public Shape
{
 private:
  float radius;
 public:
  //Constructor
  Circle(float r=1) {radius = r; }
  //Facilitators
  float Area() {return 3.1425*radius*radius;}
  float Perimeter() {return 2*(3.1425*radius);}
};

int main()
{
 Shape *ptr = new Rectangle(10,5);
 cout<<"Area of rectangle: "<<ptr->Area()<<endl;
 cout<<"Perimeter of rectangle: "<<ptr->Perimeter()<<endl;
 
 ptr = new Circle(10);
 cout<<"Area of Circle: "<<ptr->Area()<<endl;
 cout<<"Perimeter of Circle: "<<ptr->Perimeter()<<endl;
 
}
