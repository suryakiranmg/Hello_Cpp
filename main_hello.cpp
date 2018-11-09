/* 
 * Multi-line Comment
 */
 
// These are preprocessor directives. They load the files which contain premade functions for your use
 
// Contains functions for data type conv, random no gen, memory mangt,search, math, sort and other general purpose funs
#include <cstdlib>
 
// Provides functions for performing input and output operations
#include <iostream>
 
// If used, can do cout instead of std::cout. But may have conflicts if you define funs that share name with the std namespace
// using namespace std;
 
// You could define you only want to use part of a namespace like below, Which allow you to use cout instead of std::cout
// using std::cout;
 
/* Code execution starts in the main fun, argc & argv is optional data to be passed to progm if it was executed in a terminal*/
// argc : Number of arguments passed
// argv : Array pointers to strings

int main(int argc, char* argv[]) {
     
    // Outputs the string Hello World to the screen followed by a newline
    // cout is your console or screen
    // << : Stream insertion operator which puts the string into the cout stream to display it
    
	std::cout << "Hello World" << std::endl;
    
    // If you compile the code into an executable program in the terminal
    // g++ main.cpp
    // And execute it : ./a.exe I Love C++
        
    // If no arguments are passed argc has a value of 1
    // We check that with if to skip printing values if none were passed
    if(argc != 1)
	    {
		// You can also create a newline with \n
		std::cout << "You entered " << argc << " arguments\n";

		// Cycles through all the values in the argc array and prints them
		// We access the values by using their index number starting at 0 
		for(int i = 0; i < argc; ++i)
			{
			 // We access each string passed by putting its index between [] called the subscript operator
			 std::cout << argv[i] << "\n";
			}
	    }
    
    // When 0 is returned that signals that the program executed without error and -1 signals an error 
    return 0;
}
 
// ---------- End of C++ Tutorial Example 1 ----------
