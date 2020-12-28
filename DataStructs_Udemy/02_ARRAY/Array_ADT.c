#include<stdio.h>
#include<stdlib.h>

struct Array
{
  int *A;
  int size;
  int length;
};

void swap (int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void Display (struct Array arr);
void Append (struct Array *arr, int x);
int LinearSearch (struct Array arr, int key);
int BinarySearch (struct Array arr, int key);
void Reverse (struct Array *arr);

void LeftShift (struct Array *arr);
void RightShift (struct Array *arr);
void LeftRotate (struct Array *arr);
void RightRotate (struct Array *arr);

void Insert2SortedArray (struct Array *arr, int x);
int IsSorted (struct Array arr);
void RearrangePosNeg (struct Array *arr);

struct Array* Merge_SortedArrays (struct Array arr1, struct Array arr2);
struct Array* Union_SortedArrays (struct Array arr1, struct Array arr2);
struct Array* Intersection_SortedArrays (struct Array arr1, struct Array arr2);
struct Array* Difference_SortedArrays (struct Array arr1, struct Array arr2);

int main ()
{
  struct Array arr1, arr2;
  arr1.size = arr2.size = 10;
  arr1.length = arr2.length = 0;
  arr1.A = (int *) malloc (sizeof (int) * arr1.size);
  arr2.A = (int *) malloc (sizeof (int) * arr2.size);

  struct Array* arr3;
  
  Append(&arr1,1); Append(&arr1,3); Append(&arr1,5); Append(&arr1,7); Append(&arr1,9); Display(arr1);
  Append(&arr2,2); Append(&arr2,4); Append(&arr2,6); Append(&arr2,8); Append(&arr2,10); Display(arr2);

  printf("Key found at %d\n", LinearSearch(arr1,5));
  printf("Key found at %d\n", BinarySearch(arr2,9));
  
  Reverse(&arr1); Display(arr1); Reverse(&arr1);
  
  LeftRotate(&arr1); Display(arr1);
  RightRotate(&arr1); Display(arr1);
  //LeftShift(&arr1); Display(arr1);
  //RightShift(&arr2); Display(arr2);
  
  Insert2SortedArray(&arr1,2); Display(arr1);
  printf("Is Sorted %d\n", IsSorted(arr1));
  
  //Append(&arr1,-1); RearrangePosNeg (&arr1); Display(arr1);
  
  arr3=Merge_SortedArrays(arr1,arr2); printf("Merge : "); Display(*arr3); 
  arr3=Union_SortedArrays(arr1,arr2); printf("Union : "); Display(*arr3); 
  arr3=Intersection_SortedArrays(arr1,arr2); printf("Intersection : "); Display(*arr3); 
  arr3=Difference_SortedArrays(arr1,arr2); printf("Difference : "); Display(*arr3);
  
  return 0;
}

//------------------------------------------------------------------------------//
void Display (struct Array arr)	//---------------------------------------------- Display
{
  printf ("Array elements: ");
  for (int i = 0; i < arr.length; i++)
    printf ("%d ", arr.A[i]);
  printf ("\n");
}

void Append (struct Array *arr, int x) //--------------------------------------- Append
{
  if (arr->length < arr->size)
    {
      arr->A[arr->length++] = x;
    }
}

int LinearSearch (struct Array arr, int key) //--------------------------------- Linear Search
{
  for (int i = 0; i < arr.length; i++)
    {
      if (arr.A[i] == key)
	return i;
    }
  return -1;
}

int BinarySearch (struct Array arr, int key) //--------------------------------- Binary Search
{
  int l = 0, h = arr.length - 1, mid;
  while (l < h)
    {
      mid = (l + h) / 2;
      if (arr.A[mid] == key)
	return mid;
      else if (key > arr.A[mid])
	l = mid + 1;
      else
	h = mid - 1;
    }
  return -1;
}

void Reverse (struct Array *arr) //--------------------------------------------- Reverse
{
  for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
      swap (&arr->A[i], &arr->A[j]);
    }
}

void LeftShift (struct Array *arr) //------------------------------------------- Left Shift
{
  for (int i = 0; i < arr->length; i++)
    {
      arr->A[i] = arr->A[i + 1];
    }
  arr->A[arr->length - 1] = 0;
}

void RightShift (struct Array *arr)	//------------------------------------------ Right Shift
{
  for (int i = arr->length - 1; i > 0; i--)
    {
      arr->A[i] = arr->A[i - 1];
    }
  arr->A[0] = 0;
}

void LeftRotate (struct Array *arr)	//------------------------------------------ Left Rotate
{
  int temp = arr->A[0];
  for (int i = 0; i < arr->length; i++)
    {
      arr->A[i] = arr->A[i + 1];
    }
  arr->A[arr->length - 1] = temp;
}

void RightRotate (struct Array *arr) //----------------------------------------- Right Rotate
{
  int temp = arr->A[arr->length - 1];
  for (int i = arr->length - 1; i > 0; i--)
    {
      arr->A[i] = arr->A[i - 1];
    }
  arr->A[0] = temp;
}

void Insert2SortedArray (struct Array *arr, int x) //--------------------------- Insert to Sorted Array
{
  if (arr->length == arr->size)
    return;

  int i = arr->length - 1;
  for (; i >= 0 && x < arr->A[i]; i--)
    {
      arr->A[i + 1] = arr->A[i];
    }
  arr->A[i + 1] = x;
  arr->length++;
}

int IsSorted (struct Array arr) //--------------------------------------------- Is Sorted
{
  for (int i = 1; i < arr.length; i++)
    {
      if (arr.A[i] < arr.A[i -1])
      {
          return 0;
      }
    }
  return 1;			//yes
}

void RearrangePosNeg (struct Array *arr) //------------------------------------- Rearrange Pos & Neg
{
  int i = 0, j = arr->length - 1;
  while (i < j)
    {
      while (arr->A[i] < 0)
	i++;
      while (arr->A[j] > 0)
	j--;
      if (i < j)
	swap (&arr->A[i], &arr->A[j]);
    }
}

struct Array* Merge_SortedArrays(struct Array arr1,struct Array arr2) //-------- Merge Sorted Arrays
{
   
    struct Array *arr3 = (struct Array*)malloc(sizeof(struct Array));;
    arr3->size =  20; arr3->length = 0; arr3->A = (int *) malloc (sizeof (int) * arr3->size);
    
    int i=0,j=0,k=0;
    while(i<arr1.length && j<arr2.length)
    {
        if(arr1.A[i]<arr2.A[j]) arr3->A[k++]=arr1.A[i++];
        else arr3->A[k++]=arr2.A[j++];
    }
    while(i<arr1.length) arr3->A[k++]=arr1.A[i++];
    while(j<arr2.length) arr3->A[k++]=arr2.A[j++];
    arr3->length = k;
    return arr3;
    
}



struct Array* Union_SortedArrays(struct Array arr1, struct Array arr2) //------- Union of Sorted Arrays
{
    struct Array* arr3 =(struct Array*)malloc(sizeof(struct Array));
    arr3->size =  20; arr3->length = 0; arr3->A = (int *) malloc (sizeof (int) * arr3->size);
    
    int i=0,j=0,k=0;
    while(i<arr1.length && j<arr2.length)
    {
        if(arr1.A[i]<arr2.A[j]) arr3->A[k++]=arr1.A[i++];
        else if(arr1.A[i]>arr2.A[j]) arr3->A[k++]=arr2.A[j++];
        else
        {
            arr3->A[k++] = arr1.A[i++]; 
            j++;
        }
    }
    while(i<arr1.length) arr3->A[k++]=arr1.A[i++];
    while(j<arr2.length) arr3->A[k++]=arr2.A[j++];
    arr3->length = k; 
    return arr3;
}

struct Array* Intersection_SortedArrays(struct Array arr1, struct Array arr2)//-- Intersection of Sorted Arrays
{
    struct Array* arr3 =(struct Array*)malloc(sizeof(struct Array));
    arr3->size =  20; arr3->length = 0; arr3->A = (int *) malloc (sizeof (int) * arr3->size);
    
    int i=0,j=0,k=0;
    while(i<arr1.length && j<arr2.length)
    {
        if(arr1.A[i]<arr2.A[j]) i++;
        else if(arr1.A[i]>arr2.A[j]) j++;
        else if(arr1.A[i]==arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++]; 
            j++;
        }
    }
    arr3->length = k;
    return arr3;
}

struct Array* Difference_SortedArrays(struct Array arr1, struct Array arr2) //--- Difference of Sorted Arrays
{
    struct Array* arr3 =(struct Array*)malloc(sizeof(struct Array));
    arr3->size =  20; arr3->length = 0; arr3->A = (int *) malloc (sizeof (int) * arr3->size);
    
    int i=0,j=0,k=0;
    while(i<arr1.length && j<arr2.length)
    {
        if(arr1.A[i]<arr2.A[j]) arr3->A[k++]=arr1.A[i++];
        else if(arr1.A[i]>arr2.A[j]) j++;
        else if(arr1.A[i]==arr2.A[j])
        {
            i++;
            j++;
        }
    }
    while(i<arr1.length) arr3->A[k++]=arr1.A[i++];
    arr3->length = k;
    return arr3;
}
