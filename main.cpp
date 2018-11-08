//Preprocessor directive - pre-made functions on objects like rand, memory mgt, data type conv, search, sort
#include <cstdlib>
#include <iostream> /* for input-output operations*/
#include <string>
#include <vector>
#include <sstream>

//To avoid using std:: before cout
/*using namespace std;   
using std::cout; */

int main(int argc, char** argv) {
    
//To output info
    std::cout <<"Hello World Suki\n";
  
    std::cout  << "Hello World Suki 2" << std ::endl;
    
    //To check if any arguments were passed
    if(argc != 1)
    {
        std::cout << "You entered" << argc << "number of arguments";
    }
    
    return 0;
    
}

