#include <iostream>
#include <list>
using namespace std;


int main ()
{
    
//-----------Constructors------------//
list<int> v1;                                 // Empty list of int
list<int> v2(4,100);                          // 4 ints with value 100
list<int> v3(v2.begin(), v2.end());           // Iterating through v2
list<int> v4(v2);                             // Copy of v2
        
int arr[5]= {1,2,3,4,5};                        // list from array
list<int> v5(arr,arr+sizeof(arr)/sizeof(int));

//-----------Display-----------------//
for(list<int>::iterator itr=v5.begin(); itr!=v5.end(); itr++)
cout<<*itr<<" ";

//-----------Modifiers-----------------//
v5.push_back(200);                                  // push to back
v5.insert(v5.begin(),100);                       // insert to location
v5.pop_back();                                  // pop from back
//v5.erase(v5.begin());                         // remove a range of elements
//v5.clear();                                     // clear all

cout<<endl<<"Size is: "<<v5.size()<<endl;
if(!v5.empty()) cout<<"Not empty"<<endl;
cout<<"Front Element : "<<v5.front()<<endl;
cout<<"Last Element : "<<v5.back()<<endl;

for(list<int>::iterator itr=v5.begin(); itr!=v5.end(); itr++)
cout<<*itr<<" ";


return 0;

}
