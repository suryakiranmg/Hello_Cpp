
#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;
    
public:
    //Parameterised constructor
    Rectangle(int l=0,int b=0)
    {
        setLength(l);
       setBreadth(b);
    }
     //Copy constructor
    Rectangle(Rectangle &r)
    {
        length = r.length;
        breadth = r.breadth;
    }

    void setLength(int l)
    {
        if(l>0) 
            length = l; 
        else 
            length = 1;
    }
void setBreadth(int b)
    {
        if(b>0) 
            breadth = b; 
        else 
            breadth = 1;
    }
int area()
{
    return length*breadth;
}
int perimeter()
{
    return 2*(length+breadth);
}

};

int main()
{
    Rectangle r1(10,5);
    Rectangle r2(r1);
    cout<<r2.area()<<endl;    
}
