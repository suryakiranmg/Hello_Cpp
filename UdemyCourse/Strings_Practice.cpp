#include <iostream>
#include<string>

using namespace std;

int main()
{
    //Length of a string
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
