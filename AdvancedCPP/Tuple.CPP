#include <iostream>
#include<tuple> // object; holds a collection of elements of different types.
using namespace std;

tuple<int,float,double> MyFun ()
{
    return {1,2.0,3.3e-7};
}

int main()
{
    tuple <char, int, float> foo; // Declaration
    foo = make_tuple ('a',1, 1.11); // Assignment
    
    // Print tuple values using get<i>(name)
    cout<<"Initial values of tuple foo : "<< get<0>(foo) <<" , "<< get<1>(foo) <<" , "<< get<2>(foo) <<endl;
    
    // Use get<i>(name) to assign values
    get<0>(foo) = 'b'; get<1>(foo) = 2;  get<2>(foo) = 2.22;
    cout<<"New values of tuple foo : "<< get<0>(foo) <<" , "<< get<1>(foo) <<" , "<< get<2>(foo) <<endl;
    
    // Find size of Tuple
    cout<<"The size of tuple is : "<< tuple_size<decltype(foo)>::value <<endl;
    
    tuple <char, int, float> goo('s',20,20.22);
    // swap goo with foo
    foo.swap(goo);
    cout<<"Values of Tuple foo : "<< get<0>(foo) <<" , "<< get<1>(foo) <<" , "<< get<2>(foo) <<endl;
    cout<<"Values of Tuple goo : "<< get<0>(goo) <<" , "<< get<1>(goo) <<" , "<< get<2>(goo) <<endl;
    
    // use tie() & ignore to pack/unpack values
    char a; int b; float c;
    tie (a,b,c) = foo;
    cout<<"Unapcked values of foo : " <<a<<" , "<<b<<" , "<<c<<endl;
    a='*'; b= 0; c=0.0;
    tie (a,ignore,c) = foo;
    cout<<"Unapcked(with ignore) values of foo : " <<a<<" , "<<b<<" , "<<c<<endl;
    
    // Concatenate 2 tuples to get a new one
    auto mytuple = tuple_cat(foo,goo);
    cout<<"Tuple after concat : "<< get<0>(mytuple) <<" , "<< get<1>(mytuple) <<" , "<< get<2>(mytuple) 
                                <<" , "<< get<3>(mytuple) <<" , "<< get<4>(mytuple) <<" , "<< get<5>(mytuple) <<endl;
                                
    
    
    
    // USE TUPLE to RETURN multiple Values from a function------------------------------------------//
    auto[a1,a2,a3] = MyFun(); //from C++17 onwards
    cout<<"Values returned : "<<a1<<" , "<<a2<<" , "<<a3<<endl;
    
    auto mytuple1 = MyFun();
    cout<<"Values returned : "<<get<0>(mytuple1)<<" , "<<get<1>(mytuple1)<<" , "<<get<2>(mytuple1)<<endl;
    
    return 0;
}

