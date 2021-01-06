#include <stdio.h>
#define BUFFER_SIZE 6

int IsBufferFull()
{
    return BufferFull_Flag;
}

int IsBufferEmpty()
{
    if( (head == tail) && (BufferFull_Flag != 1) ) return 1; //full and indexes are equal
    else retrun 0;
}

void API_WriteToBuffer(int data)
{
    if(IsBufferFull()) 
    {
        printf("Buffer is full\n");
    }
    else
    {
        CircularBuffer[head] = data; //write
        printf("Data written to Buffer: %d", CircularBuffer[head]);
        head = (head+1) % BUFFER_SIZE; //update head index
        if(head==tail) BufferFull_Flag = 1; //check if full
    }
}

void API_ReadFromBuffer(int* data)
{
    if(IsBufferEmpty()) 
    {
        printf("Buffer is Empty\n");
    }
    else
    {
        *data = CircularBuffer[tail]; //read
        printf("Read from Buffer: %d", CircularBuffer[tail]);
        tail = (tail+1) % BUFFER_SIZE; //update tail index
        BufferFull_Flag = 0; //not full after read
    }
}

int main()
{
    printf("Hello World");

    return 0;
}
