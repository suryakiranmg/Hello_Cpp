#include <iostream>
#include <stdlib.h> //rand(),srand()
using namespace std;

unsigned int My_PRNG()
{
    static unsigned int seed{5323};
    seed = 8253729 * seed + 2396403;
    return seed%32768; // value between 0 to 32767
}

int main ()
{
    //-----Method -1 : Create own
    for(int i=1,t; i<=100; i++)
    {
        t=My_PRNG();
        cout<<(t%100)<<'\t'; //between 0 to 100
        if(i%5==0) cout<<endl;
    }cout<<endl<<endl;
    
    //-----Method -2 : Use lib functions
    srand(5323); // seed
    rand(); // due to flow in some compliers, reject the first value
    for(int i=1,t; i<=100; i++)
    {
        cout<<rand()%100<<'\t'; // between 0 to 100
        if(i%5==0) cout<<endl;
    }
    
    //-----Method -3 : Use Mersenne Twister----- #include <random> // for mt19937
    
    return 0;
}
