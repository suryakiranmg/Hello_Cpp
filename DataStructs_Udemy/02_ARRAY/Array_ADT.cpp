//-------------------------- ARRAY ADT -- Array Class in C++ -------------------//
#include<iostream>
using namespace std;

template<class T>
class Array
{
private:        // Data
    T *A;       // Dynamic array
    int size;
    int length; 
    
    void swap(T *a, T *b) { T temp; temp = *a; *a=*b; *b=temp;}
    
public:
    // Constructor
    Array() { size = 10; length = 0; A = new T[10]; }       
    Array(int size)  { this->size = size; length = 0;  A= new T[size];  }
    // Destructor
    ~Array() { delete []A; A = nullptr; }  
    
    // Functions Prototypes
    void Display();                 // Display - O(n)
    void Insert(int index, T x);    // Insert  - O(n)
    void Append(T x);               // Append  - O(1)
    T Delete(int index);            // Delete  - O(n)

    int LinearSearch(T key);        // Linear Search (Move to front)  - O(n)
    int BinarySearch(T key);        // Binary Search (only on sorted) - O(log n)
    
    T Get(int index);               // Get  - O(1)
    void Set(int index, T x);       // Set  - O(1)  
    T Max();                        // Max  - O(n)
    T Min();                        // Min  - O(n)
    T Sum();                        // Sum  - O(n)
    float Avg();                    // Avg  - O(n)
    
    void Reverse();                 // Reverse      - O(n)
    void LeftShift();               // Left Shift   - O(n)
    void LeftRotate();              // Left Rotate  - O(n)
    void RightShift();              // Right Shift  - O(n)
    void RightRotate();             // Right Rotate - O(n)
    
    void Insert2SortedArray(T x);   // Insert to Sorted Array  - O(n)   
    bool IsArraySorted();           // Is Array Sorted         - O(n)
    void RearrangeArray();          // Rearrange to PosNeg     - O(n)
    
    Array* MergeSorted(Array arr2);         // Merge        - O(n)
    Array* UnionSorted(Array arr2);         // Union        - O(n)
    Array* DifferenceSorted(Array arr2);    // Difference   - O(n)
    Array* IntersectionSorted(Array arr2);  // Intersection - O(n)
 
};

//----------------------------Function Definitions------------------------------//
template<class T>
void Array<T>::Display()                    // Display
{
    for(int i=0;i<length;i++)  cout<<A[i]<<" ";
    cout<<endl;
}

//------------------------------------------------------------- Insert
template<class T>
void Array<T>::Insert(int index, T x)       
{
    if(index>=0 && index<=length)       
    {
        for(int i=(length-1); i>index; i--) A[i+1]=A[i];
        A[index]=x;
        length++;
    }
}

//------------------------------------------------------------ Delete
template<class T>
T Array<T>::Delete(int index)               
{
    if(index>=0 && index < length)
    {
        T x=A[index];
        for(int i=index;i<length-1;i++)  A[i]=A[i+1];
        length--;
        return x;      
    }
}

//------------------------------------------------------------ Append
template<class T>
void Array<T>::Append(T x)                  
{
    if(length<size) A[length++] = x;
}

//------------------------------------------------------------ Linear Search
template<class T>
int Array<T>::LinearSearch(T key)           
{
    for(int i=0;i<length;i++)
    { 
        if(A[i]==key) 
        {
            swap(&A[i],&A[0]);
            return i; // return index
        }
    }
    return -1;
}

//------------------------------------------------------------ Binary Search
template<class T>
int Array<T>::BinarySearch(T key)           
{
    int l=0, h=length-1, mid;
    while(l<=h)
    {
     mid = (l+h)/2;
     if(A[mid]==key) return mid;
     else if(A[mid]>key) h=mid-1;
     else l=mid+1;
    }
    return -1;
}

//------------------------------------------------------------ Get
template<class T>
T Array<T>::Get(int index)                  
{
    return A[index];
}

//------------------------------------------------------------ Set
template<class T>
void Array<T>::Set(int index, T x)          
{
    A[index] = x;
}

//------------------------------------------------------------ Sum
template<class T>
T Array<T>::Sum()                           
{
    T sum=0;
    for(int i=0;i<length; i++)
       sum += A[i];
    return sum;
}

//------------------------------------------------------------ Average
template<class T>
float Array<T>::Avg()                        
{
    return (float)Sum()/length;
}

//------------------------------------------------------------ Max
template<class T>
T Array<T>::Max()                           
{
    T max=A[0];
    for(int i=1;i<length;i++)
    {
        if(A[i]>max) max = A[i];
    }
    return max;
}

//------------------------------------------------------------ Min
template<class T>
T Array<T>::Min()                           
{
    T min=A[0];
    for(int i=1;i<length;i++)
    {
        if(A[i]<min) min = A[i];
    }
    return min;
}

//------------------------------------------------------------ Reverse
template<class T>
void Array<T>::Reverse()                    
{
    for(int i=0,j=length-1;i<j;i++,j--)
        swap(&A[i],&A[j]);   
}

//------------------------------------------------------------ Left Shift
template<class T>
void Array<T>::LeftShift()                  
{
    for(int i=0;i<length-1;i++) A[i]=A[i+1];
    A[length-1] = 0;
}

//------------------------------------------------------------ Left Rotate
template<class T>
void Array<T>::LeftRotate()             
{
    T temp = A[0];
    for(int i=0;i<length-1;i++) A[i]=A[i+1];
    A[length-1]= temp;    
}

//------------------------------------------------------------ Right Shift
template<class T>
void Array<T>::RightShift()             
{
    for(int i=length-1;i>0;i--) A[i]=A[i-1];
    A[0]=0;       
}

//------------------------------------------------------------ Right Rotate
template<class T>
void Array<T>::RightRotate()            
{
    T temp = A[length-1];
    for(int i=length-1;i>0;i--) A[i]=A[i-1];
    A[0]= temp;
}

//------------------------------------------------------------ Is Array Sorted
template<class T>
bool Array<T>::IsArraySorted()          
{
    for(int i=0;i<length-1;i++)
    {
        if(A[i]>A[i+1]) return 0;
    }
    return 1;
}

//------------------------------------------------------------ Insert to Sorted Array
template<class T>
void Array<T>::Insert2SortedArray(T x)  
{
    if(length<size)
    {
        int i= length-1;
        while(i>=0 && A[i]>x)
        {
            A[i+1]=A[i];
            i--;
        } 
        A[i+1] = x;
        length++;
    }
}

//------------------------------------------------------------ Rearrange Array
template<class T>
void Array<T>::RearrangeArray()         
{
    int i=0,j=length-1;
    while(i<j)
    {
        while(A[i]<0) i++;
        while(A[j]>0) j--;
        if(i<j) swap(&A[i],&A[j]);
    }
}

//------------------------------------------------------------ Merge 2 Sorted Arrays
template<class T>
Array<T>* Array<T>::MergeSorted(Array arr2)    
{
    int i=0, j=0, k=0;
    Array<T> *arr3 = new Array[length + arr2.length];
    if((arr3->size)>=(length + arr2.length))
    {
        while(i<length && j<arr2.length)
        {
            if(A[i]<arr2.A[j]) arr3->A[k++] = A[i++];
            else  arr3->A[k++] = arr2.A[j++];
        }
        for(;i<length;i++) arr3->A[k++] = A[i++];
        for(;j<length;j++) arr3->A[k++] = A[j++];
        arr3->length = length + arr2.length;
    }           
    return arr3;
}

//------------------------------------------------------------ Reverse
template<class T>
Array<T>* Array<T>::UnionSorted(Array arr2)
{
    Array<T> *arr3 = new Array[length+arr2.length];
    int i=0, k=0, j=0;
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j]) arr3->A[k++] = A[i++];
        else if(A[i]>arr2.A[j]) arr3->A[k++] = arr2.A[j++];
        else 
        {
            arr3->A[k++]= A[i++]; 
            j++;
        }          
    }
    for(;i<length;i++) arr3->A[k++] = A[i];
    for(;j<arr2.length;j++) arr3->A[k++] = arr2.A[j];
    //update length of Array3
    arr3->length = k;   
    return arr3;
}

//------------------------------------------------------------ Reverse
template<class T>
Array<T>* Array<T>::DifferenceSorted(Array arr2)
{
    Array<T> *arr3 = new Array[length+arr2.length];
    int i=0, j=0,k=0;
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j]) arr3->A[k++] = A[i++];
        else if (A[i]>arr2.A[j]) j++;
        else 
        {
            i++;j++;
        }
    }
    for(;i<length;i++) arr3->A[k++] = A[i];
    arr3->length = k;  
    return arr3;
}

//------------------------------------------------------------ Reverse
template<class T>
Array<T>* Array<T>::IntersectionSorted(Array arr2)
{
    Array<T> *arr3 = new Array[length+arr2.length];
    int i=0, j=0,k=0;
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j]) i++;
        else if(A[i]>arr2.A[j]) j++;
        else if(A[i]==arr2.A[j])
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    arr3->length = k;    
    return arr3;
}




int main()
{
    // Insert
    Array<int> arr(10);
    arr.Insert(0,98); arr.Insert(1,36); arr.Insert(2,14); arr.Insert(3,11);
    cout<<"Array is :"; arr.Display();
    
    // Delete
    cout<<"Deleted : "<<arr.Delete(0)<<endl;
    cout<<"Array is :"; arr.Display();
    
    // Append
    Array<int> arr2(10);
    arr2.Append(3); arr2.Append(5); arr2.Append(14);arr2.Append(20);
    cout<<"Array2 is :"; arr2.Display();
    
    // Search
    (arr.LinearSearch(14)==-1)?cout<<"14 Not Present"<<endl:cout<<"14 present at "<<arr.LinearSearch(14)<<endl;
    (arr.BinarySearch(98)==-1)?cout<<"98 Not Present"<<endl:cout<<"98 present at "<<arr.BinarySearch(98)<<endl;
    (arr.BinarySearch(20)==-1)?cout<<"20 Not Present"<<endl:cout<<"98 present at "<<arr.BinarySearch(20)<<endl;
    
    // Get, Set, Max, Min, Sum, Avg
    arr.Set(1,33);
    cout<<"Value at index 1 is "<<arr.Get(1)<<endl;
    cout<<"Max is "<<arr.Max()<<" Min is "<<arr.Min()<<" Sum is "<<arr.Sum()<<" Avg is "<<arr.Avg()<<endl;
    
    // Reverse, Rotate
    arr.Reverse(); cout<<"Reverse "; arr.Display();
    arr.LeftRotate(); cout<<"Left Rotate "; arr.Display();
    arr.RightRotate(); cout<<"Right Rotate "; arr.Display();
    arr.LeftShift(); cout<<"Left Shift "; arr.Display();
    arr.RightShift(); cout<<"Right Shift "; arr.Display();
    
    // Insert, IsSorted, Rearrange
    (arr.IsArraySorted()==1)?cout<<"Sorted"<<endl:cout<<"Not Sorted"<<endl;
    arr2.Insert2SortedArray(-1);
    arr.RearrangeArray();
    cout<<"Array is :"; arr.Display();
    
    // Merge,Union, Difference, Intersection
    /*cout<<"Array :  "; arr.Display();
    cout<<"Array2 :  "; arr2.Display();
    Array<int> *arr3;
    cout<<"Merge: ";
    arr3 = arr.MergeSorted(arr2); arr3->Display();
    cout<<"Union: ";
    arr3 = arr.UnionSorted(arr2); arr3->Display();
    cout<<"Diff: ";
    arr3 = arr.DifferenceSorted(arr2); arr3->Display();
    cout<<"Intersection: ";
    arr3 = arr.IntersectionSorted(arr2); arr3->Display();
    */
    return 0;
}
