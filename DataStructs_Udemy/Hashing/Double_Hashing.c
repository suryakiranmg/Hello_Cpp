#include<stdio.h>
#define SIZE 10
#define PRIME 7

int Hash(int key)
{
    return key%SIZE;
}

int PrimeHash(int key)
{
    return PRIME - (key%PRIME);
}

int DoubleHash(int H[], int key)
{
    int index = Hash(key);
    
    int i=0; //find free slot
    while(H[(Hash(key)+i*PrimeHash(key))%SIZE] != 0) i++;
    
    return (Hash(key)+i*PrimeHash(key))%SIZE ; // return index
}


void Insert(int H[], int key)
{
    int index = Hash(key);
    
    if(H[index]!=0) index = DoubleHash(H,key);
    
    H[index] = key;
}


int Search(int H[], int key)
{
    int index = Hash(key);
    int i=0;
    
    while(H[(Hash(key)+i*PrimeHash(key))%SIZE] != key)
    {
        i++;
        if(i>SIZE) return -1; //Key Not Present
    }
    return (Hash(key)+i*PrimeHash(key))%SIZE;
}


int main()
{
    int H[10]={0};
    
    Insert(H,5);
    Insert(H,25);
    Insert(H,15);
    Insert(H,35);
    Insert(H,95);
    
    printf("Key Found at  %d\n", Search(H,36));
    printf("Key Found at  %d\n", Search(H,25));
    
    return 0;
}
