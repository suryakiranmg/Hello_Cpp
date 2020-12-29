#include<iostream>
using namespace std;

void Upper2LowerCase(char A[]) //-----------------------------------------------Upper to lower case
{
    for(int i=0; A[i]!='\0'; i++)
    {
        A[i] += 'a'-'A'; //+35
    }
}

void Lower2UpperCase(char A[]) //-----------------------------------------------Lower to upper case
{
    for(int i=0; A[i]!='\0'; i++)
    {
        A[i] -= 'a'-'A'; //-35
    }
}

void ToggleCase(char* A) //-----------------------------------------------------Toggle case
{
    for(int i=0; A[i] !='\0'; i++)
    {
        if(A[i] >='a' && A[i] <='z') A[i] -= 'a'-'A';
        else if(A[i] >='A' && A[i] <='Z') A[i] += 'a'-'A';
    }
}

void Count_WordsVowelsConsonants(char* A) //------------------------------------Count vowels, words, Consonants
{
    int vowels=0, consonants=0, words=1;
    for(int i=0; A[i] !='\0'; i++)
    {
        if(A[i] >='A' && A[i] <='Z') A[i] += 'a'-'A'; // all lower
        
        if(A[i] =='a' || A[i] =='e' || A[i] =='i' || A[i] =='o' || A[i] =='u') vowels++;
        else if(A[i] >='a' && A[i] <='z') consonants++;
        
        if(A[i] == ' ' && A[i+1] != ' ') words++;
    }
    cout<<endl<<"Vowels :"<<vowels<<"  Consonants :"<<consonants<<"  Words :"<<words<<endl;
}

int ValidateUsername(char* A) //------------------------------------------------Check if valid username
{
    for(int i=0; A[i] !='\0'; i++)
    {
        if( !(A[i]>='A' && A[i]<='Z') && !(A[i]>='a' && A[i]<='z') && !(A[i]>='0' && A[i]<='9')) return 0;
    }
    return 1;
}

void Reverse_String(char* A) //-------------------------------------------------Reverse string
{
    int j; char temp;
    for(j=0; A[j] !='\0'; j++) {}
    j--;
    for(int i=0; i<j ; i++,j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

int Palindrome_Check(char* A) //------------------------------------------------Check if palindrome
{
    int j;
    for(j=0; A[j] !='\0'; j++) {}
    j--;
    for(int i=0; i<j ; i++,j--)
    {
        if(A[i] != A[j]) return 0; 
    }
    return 1;
}

void Compare_Strings(char* A, char* B) //---------------------------------------Compare strings
{
    int i,j;
    for(i=0,j=0; A[i] !='\0' && B[i] !='\0'; i++,j++)
    {
        if(A[i] != B[j]) break;
    }
    
    if(A[i]==B[j]) cout<<"Equal Strings"<<endl;
    else if(A[i]>B[j]) cout<<"Greater"<<endl;
    else cout<<"Smaller"<<endl;
}

void Find_Duplicates(char* A) // -----------------------------------------------Find  duplicate letters using bit map
{
    int H=0, mask;
    for(int i=0; A[i] != '\0'; i++)
    {
        if(A[i]>='a' && A[i]<='z')
        {
            mask =1;
            mask = mask<<(A[i]-'a') ;
            if((mask & H) >0) cout<<A[i]<<" is duplicate"<<endl;
            else H = H | mask;
        }
    }
}

int Anagram_Check(char* A, char* B) // -----------------------------------------Check if Anagram using hash array
{
    int i,j;
    for(i=0; A[i] != '\0'; i++){}
    for(j=0; B[j] != '\0'; j++){}
    if(i!=j) return 0;
    
    int H[26]={0};
    for(i=0; A[i] != '\0'; i++)
    {
        H[A[i]-'a']++;
    }
    for(i=0; B[i] != '\0'; i++)
    {
        H[B[i]-'a']--;
        if(H[B[i]-'a']<0) return 0;
    }
    return 1;
}


int main()
{
    char A[]= "WELCOME";
    Upper2LowerCase(A); cout<<A<<endl;
    Lower2UpperCase(A); cout<<A<<endl;
    
    char B[]= "Suryakiran   Menachery     George";
    ToggleCase(B); cout<<B<<endl;
    Count_WordsVowelsConsonants(B);
    
    char C[]= "User123?";
    cout<<"Username Validity :"<<ValidateUsername(C)<<endl;
    
    char D[]= "MalayalaM";
    Reverse_String(D); cout<<D<<endl; 
    cout<<"Is Palindrome :"<<Palindrome_Check(D)<<endl;
    
    char E[] = "Discover", F[] = "Discovery";
    Compare_Strings(E,F);
    
    char G[] = "any duplicates?";
    Find_Duplicates(G);

    char H[] = "decimal", I[] = "medical";
    cout<<"Is Anagram : "<<Anagram_Check(H,I)<<endl;
 

    return 0;
}
