#include <iostream>
using namespace std;

int main()
{
  int A[3][2];
  //To enter the 2D array
  for(auto& x:A)
    {
      for(auto& y:x)
      {
       cin>>y;;
      }
    }
  
  //To display the 2D array
  for(auto& x:A)
    {
      for(auto& y:x)
      {
       cout<<y<<" ";
      }
      cout<<endl;
    }
  
  return 0;
}
