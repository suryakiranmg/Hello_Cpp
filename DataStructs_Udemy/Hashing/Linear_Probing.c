#include<stdio.h>
#define SIZE 10

int Hash(int key)
{
    return key%SIZE;
}


int Probe(int H[], int key)
{
    int index = Hash(key);
    
    int i=0; //find free slot
    while(H[(index+i)%SIZE] != 0) i++;
    
    return (index+i)%SIZE ; // return index
}


void Insert(int H[], int key)
{
    int index = Hash(key);
    
    if(H[index]!=0) index = Probe(H,key);
    
    H[index] = key;
}


int Search(int H[], int key)
{
    int index = Hash(key);
    int i=0;
    
    while(H[(index+i)%SIZE] != key)
    {
        i++;
        if(i>SIZE) return -1; //Key Not Present
    }
    return (index+i)%SIZE;
}


int main()
{
    int H[10]={0};
    
    Insert(H,12);
    Insert(H,25);
    Insert(H,35);
    Insert(H,26);
    
    printf("Key Found at  %d\n", Search(H,36));
    printf("Key Found at  %d\n", Search(H,12));
    
    return 0;
}
