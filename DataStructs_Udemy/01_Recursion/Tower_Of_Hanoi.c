//-------------Tower of Hanoi using recursion

#include<stdio.h>

void TOH(int n, int A, int B, int C)
{   
    if(n>0)
    {     
        TOH(n-1,A,C,B);
        printf("(%d,%d) ",A,C);  //Move from A to C
        TOH(n-1,B,A,C);
    }    
}
int main()
{
    TOH(5,1,2,3);
    return 0;
}
