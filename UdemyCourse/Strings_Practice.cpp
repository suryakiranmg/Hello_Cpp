#include <iostream>
#include<string>
using namespace std;

//-------------------Length of a String--------------------------------------------------//
int main()
{
    string str = "Hello Suki";
    
    int count=0;
    for(int i=0; str[i] !='\0'; i++) count++;
    cout<<"Lenth - normal method : "<<count<<endl;
    
    count=0; string::iterator itr;
    for(itr=str.begin(); itr!=str.end(); itr++) count++;
    cout<<"Lenth - using iterator : "<<count<<endl;
    
    cout<<"Lenth - using function1 : "<<str.length()<<endl;
    cout<<"Lenth - using function2 : "<<str.size()<<endl;
    
    return 0;
}


//-------------------Interchange Case ( lower to UPPER & back )------------------------//
int main()
{
    string str = "Hello Suki 2020";
  
    for(int i=0; str[i] !='\0'; i++) //all lower
    {
        if(str[i]>=65 && str[i]<=90) cout<<char(str[i]+32);
        else cout<<str[i];
    }
    cout<<endl;
    for(int i=0; str[i] !='\0'; i++) //all upper
    {
        if(str[i]>=97 && str[i]<=122) cout<<char(str[i]-32);
        else cout<<str[i];
    }
    
    return 0;
}
