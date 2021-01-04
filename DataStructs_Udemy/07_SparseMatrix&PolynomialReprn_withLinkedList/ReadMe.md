
##  Sparse Matrix representation & Polynomial Representation Using Linked List
- Create
- Display
- Add


## -- Matrix --

struct Node\
{
- int column;
- int Value;
- struct Node *next;\
};


#### struct Node* A[m];   // m = # of rows   (Array of pointers to each row's elements )


## -- Polynomial --

struct Node\
{
- int coefft;
- int expt;
- struct Node* next;\
};

