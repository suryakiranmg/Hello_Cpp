#include <iostream>
#include <utility> // for std::swap

void SelectionSort ( int* arr, int size, bool(*ComparisonFun)(int, int) )
{
    for(int i=0; i<size-1; i++)
    {
        int sel_index = i;
        for(int j=i+1; j<size; j++)
        {
            if(ComparisonFun(arr[sel_index],arr[j]))
            {
                sel_index = j;
            }
        }
        std::swap(arr[sel_index],arr[i]);
    }
}

bool Ascending  (int x, int y) { return x>y; }
bool Descending (int x, int y) { return x<y; }
bool MyCompare  (int x, int y) //---------------Define Strange Compare Funs as well with Function Ptr
{
    if( x%2 == 0 && y%2 != 0 ) return false; // x even, y odd
    if( x%2 != 0 && y%2 == 0 ) return true;  // x odd, y even
    return Ascending (x,y); // if both even/odd, ascending order
}


void DisplayArray (int* arr, int size)
{
    for(int i=0; i<size; i++) std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}

int main()
{
    int arr[]={3,7,9,5,6,1,8,2,4}; int n=sizeof(arr)/sizeof(arr[0]);
    
    SelectionSort (arr,n,Descending); DisplayArray (arr,n);
    SelectionSort (arr,n,Ascending);  DisplayArray (arr,n);
    SelectionSort (arr,n,MyCompare);  DisplayArray (arr,n);
    
    return 0;
}
