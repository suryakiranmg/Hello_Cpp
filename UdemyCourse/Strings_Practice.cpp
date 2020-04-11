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


//-------------------Count Vowels, Words(discard multiple spaces), Consonants(take only letters)------------------------//
int main()
{
    string str = "Hello Suki      2020";
    
    uint vowel=0,words=0,consonant=0;
    for(int i=0; str[i] !='\0'; i++) 
    {
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||
           str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U') 
        vowel++;
        else if(str[i]==' ' && str[i+1]!=' ') words++; //in case of multiple spaces
        else if(str[i]!=' ' && ((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))) consonant++;
    }
    cout<<"Vowels= "<<vowel<<", Words= "<<words+1<<", Consonants= "<<consonant<<endl;
    
    return 0;
}


//---------------------------Checking Palindrome-----------------------------//
int main() 
{
    string str = "-MalAyalam-";
    int pass=1;
    
    for(int i=0; str[i] !='\0'; i++) // All lower-case
    {
     if(str[i]>=65 && str[i]<=90) str[i] += 32;
    }
    
    int len = str.length();
    for(int i=0,j=len-1; i<len; i++,j--) // Reverse the string
    {
     if(str[j]!=str[i]) 
     {
         pass=-1; break;
     }
    }
   
    if(pass==-1) cout<<"Not Palindrome";
    else cout<<"Palindrome";
    
    return 0;
}


//--------------------------- Finding Username from Email -----------------------------//
int main() 
{
    string str = "suki_suki@gmail.com";
    
    int index = str.find('@');
    string Uname = str.substr(0,index);
    
    for(int i=0; Uname[i]!='\0'; i++) 
    {
        if((str[i]>=65&&str[i]<=90)||(str[i]>=97&&str[i]<=122)||(str[i]>=48&&str[i]<=57)||str[i]=='.'||str[i]=='_') {}
        else 
        {
            Uname = "Invalid";
            break;
        }
        
    }
    cout<<"Username is : "<<Uname;
    return 0;
}
