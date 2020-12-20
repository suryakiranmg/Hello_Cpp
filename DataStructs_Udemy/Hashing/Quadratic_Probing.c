#include<stdio.h>
#define SIZE 10

int Hash(int key)
{
    return key%SIZE;
}


int QuadraticProbe(int H[], int key)
{
    int index = Hash(key);
    
    int i=0; //find free slot
    while(H[(index+i*i)%SIZE] != 0) i++;
    
    return (index+i*i)%SIZE ; // return index
}


void Insert(int H[], int key)
{
    int index = Hash(key);
    
    if(H[index]!=0) index = QuadraticProbe(H,key);
    
    H[index] = key;
}


int Search(int H[], int key)
{
    int index = Hash(key);
    int i=0;
    
    while(H[(index+i*i)%SIZE] != key)
    {
        i++;
        if(i>SIZE) return -1; //Key Not Present
    }
    return (index+i*i)%SIZE;
}


int main()
{
    int H[10]={0};
    
    Insert(H,23);
    Insert(H,43);
    Insert(H,13);
    Insert(H,27);
    
    printf("Key Found at  %d\n", Search(H,36));
    printf("Key Found at  %d\n", Search(H,27));
    
    return 0;
}
