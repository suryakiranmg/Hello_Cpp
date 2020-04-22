#include <iostream>
#include <vector>
using namespace std;


int main ()
{
    
//-----------Constructors------------//
vector<int> v1;                                 // Empty vector of int
vector<int> v2(4,100);                          // 4 ints with value 100
vector<int> v3(v2.begin(), v2.end());           // Iterating through second
vector<int> v4(v2);                             // Copy of third
        
int arr[5]= {1,2,3,4,5};                        // vector from array
vector<int> v5(arr,arr+sizeof(arr)/sizeof(int));

//-----------Display-----------------//
for(vector<int>::iterator itr=v5.begin(); itr!=v5.end(); itr++)
cout<<*itr<<" ";

//-----------Modifiers-----------------//
v5.push_back(200);                                  // push to back
v5.insert(v5.begin()+1,100);                       // insert to location
//v5.pop_back();                                  // pop from back
//v5.erase(v5.begin()+1);                         // remove a range of elements
//v5.clear();                                     // clear all

cout<<endl<<"Size is: "<<v5.size()<<endl;

for(vector<int>::iterator itr=v5.begin(); itr!=v5.end(); itr++)
cout<<*itr<<" ";

if(!v5.empty()) cout<<endl<<"not empty";

return 0;

}
