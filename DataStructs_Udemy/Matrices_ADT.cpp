#include<iostream>
using namespace std;

//----------Class Upper Triangular - Column Major--------//
class UpperTri_ColMaj
{
private: 
    int n;
    int *A;
public:
    UpperTri_ColMaj(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() {return this->n;}
    ~UpperTri_ColMaj() {delete []A;}    
};

void UpperTri_ColMaj::Set(int i, int j, int x)
{
    if(i<=j) A[j*(j-1)/2+(i-1)] = x;
}

int UpperTri_ColMaj::Get(int i, int j)
{
    if(i<=j) return A[j*(j-1)/2+(i-1)];
    else return 0;
}
void UpperTri_ColMaj::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=n;j++)
        {
            if(i<=j) cout<<" "<<A[j*(j-1)/2+(i-1)];
            else cout<<" "<<0;
        }
        cout<<endl;
    }
}
//-------------------------------------//

//----------Class Upper Triangular - Row Major-----------//
class UpperTri_RowMaj
{
private: 
    int n;
    int *A;
public:
    UpperTri_RowMaj(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() {return this->n;}
    ~UpperTri_RowMaj() {delete []A;}    
};

void UpperTri_RowMaj::Set(int i, int j, int x)
{
    if(i<=j) A[n*(i-1)-(i-2)*(i-1)/2+(j-i)] = x;
}

int UpperTri_RowMaj::Get(int i, int j)
{
    if(i<=j) return A[n*(i-1)-(i-2)*(i-1)/2+(j-i)];
    else return 0;
}
void UpperTri_RowMaj::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=n;j++)
        {
            if(i<=j) cout<<" "<<A[n*(i-1)-(i-2)*(i-1)/2+(j-i)];
            else cout<<" "<<0;
        }
        cout<<endl;
    }
}
//-------------------------------------//

//----------Class Lower Triangular - Column Major--------//
class LowerTri_ColMaj
{
private: 
    int n;
    int *A;
public:
    LowerTri_ColMaj(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() {return this->n;}
    ~LowerTri_ColMaj() {delete []A;}    
};

void LowerTri_ColMaj::Set(int i, int j, int x)
{
    if(i>=j) A[n*(j-1)-(j-2)*(j-1)/2+(i-j)] = x;
}

int LowerTri_ColMaj::Get(int i, int j)
{
    if(i>=j) return A[n*(j-1)-(j-2)*(j-1)/2+(i-j)];
    else return 0;
}
void LowerTri_ColMaj::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=n;j++)
        {
            if(i>=j) cout<<" "<<A[n*(j-1)-(j-2)*(j-1)/2+(i-j)];
            else cout<<" "<<0;
        }
        cout<<endl;
    }
}
//-------------------------------------//

//----------Class Lower Triangular - Row Major-----------//
class LowerTri_RowMaj
{
private: 
    int n;
    int *A;
public:
    LowerTri_RowMaj(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension() {return this->n;}
    ~LowerTri_RowMaj() {delete []A;}    
};

void LowerTri_RowMaj::Set(int i, int j, int x)
{
    if(i>=j) A[i*(i-1)/2 + (j-1)] = x;
}

int LowerTri_RowMaj::Get(int i, int j)
{
    if(i>=j) return A[i*(i-1)/2 + (j-1)];
    else return 0;
}
void LowerTri_RowMaj::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=n;j++)
        {
            if(i>=j) cout<<" "<<A[i*(i-1)/2 + (j-1)];
            else cout<<" "<<0;
        }
        cout<<endl;
    }
}
//-------------------------------------//

//----------Class Diagonal-----------//
class Diagonal
{
private: 
    int n;
    int *A;
public:
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~Diagonal() {delete []A;}    
};

void Diagonal::Set(int i, int j, int x)
{
    if(i==j) A[i-1] = x;
}

int Diagonal::Get(int i, int j)
{
    if(i==j) return A[i-1];
    else return 0;
}
void Diagonal::Display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n;j++)
        {
            if(i==j) cout<<" "<<A[i-1];
            else cout<<" "<<0;
        }
        cout<<endl;
    }
}
//-------------------------------------//

int main()
{
    //Diagonal
    Diagonal D(3);
    D.Set(0,0,1); D.Set(1,1,2); D.Set(2,2,3);
    cout<<"Diagonal"<<endl;
    D.Display();
    cout<<endl;
    //Lower Triangular - Row Major
    LowerTri_RowMaj LR(3);
    LR.Set(1,1,1);LR.Set(2,1,2);LR.Set(2,2,3);
    LR.Set(3,1,4);LR.Set(3,2,5);LR.Set(3,3,6);
    cout<<"Lower Tri - Row Major Map"<<endl;
    LR.Display();
    cout<<endl;
    //Lower Triangular - Col Major
    LowerTri_ColMaj LC(3);
    LC.Set(1,1,1);LC.Set(2,1,2);LC.Set(2,2,3);
    LC.Set(3,1,4);LC.Set(3,2,5);LC.Set(3,3,6);
    cout<<"Lower Tri - Col Major Map"<<endl;
    LC.Display();
    cout<<endl;  
    //Upper Triangular - Row Major
    UpperTri_RowMaj UR(3);
    UR.Set(1,1,1);UR.Set(1,2,2);UR.Set(1,3,3);
    UR.Set(2,2,4);UR.Set(2,3,5);UR.Set(3,3,6);
    cout<<"Upper Tri - Row Major Map"<<endl;
    UR.Display();
    cout<<endl;
    //Upper Triangular - Col Major
    UpperTri_ColMaj UC(3);
    UC.Set(1,1,1);UC.Set(1,2,2);UC.Set(1,3,3);
    UC.Set(2,2,4);UC.Set(2,3,5);UC.Set(3,3,6);
    cout<<"Upper Tri - Col Major Map"<<endl;
    UC.Display();
    cout<<endl;
    
    return 0;
}
