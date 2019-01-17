#include<iostream>
#include<memory>
using namespace std;

class Rectangle
{
    int length;
    int breadth;
public:
    Rectangle(int length, int breadth)
    {
        this->length = length;    this->breadth = breadth;
    }
    int Area() { return length*breadth; }
    int Perimeter() {return 2*(length+breadth);}
};

int main()
{
    //unique pointer
    unique_ptr<Rectangle> ptr (new Rectangle(10,5));
    cout<<"Area is "<<ptr->Area()<<endl;
    
    //move the pointer to another pointer
    unique_ptr<Rectangle> ptr2 = move(ptr);
    cout<<"Area is "<<ptr2->Area()<<endl;
    
    //shared pointer
     shared_ptr<Rectangle> ptr3 (new Rectangle(10,5));
    //assign the pointer to another -- shared
    shared_ptr<Rectangle> ptr4 = ptr3;
    cout<<"Area is (ptr3) "<<ptr3->Area()<<endl;
    cout<<"Area is (ptr4) "<<ptr4->Area()<<endl;
    cout<<"Use_count of shared ptr: "<<ptr4.use_count()<<endl;
    
}
