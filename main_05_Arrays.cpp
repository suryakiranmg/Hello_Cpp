// ---------- C++ Tutorial Example 4 —————
 
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
 
int main() {
     
    // An array is a collection of data of the same type
    // Declare an array of ints with the value of 1, Once the size is defined it can't change
    int arrnNums1[10] = {1};
    
    // Leave out the array length, here size = 3
    int arrnNums2[] = {1,2,3};
    
    // Create an array and assign some values and leave out the rest
    int arrnNums3[5] = {8, 9};
    
    // Access array values using indexes starting with 0
    std::cout << "1st Value : " << arrnNums3[0] << "\n";
    
    // Change a value
    arrnNums3[0] = 7;
    std::cout << "1st Value : " << arrnNums3[0] << "\n";
    
    // Get array size by getting # bytes set aside for the array & then divide by size of 1st element
    std::cout << "Array size : " << sizeof(arrnNums3) / sizeof(*arrnNums3) << "\n"; //indirection operator
    
    // A multidimensional array is like a spreadsheet, think of each as layers that contain rows & columns
    // 1st Number : Which layer (like page)
    // 2nd Number : Which column
    // 3rd Number : Which row
    int arrnNums4[2][2][2] = {{{1,2}, {3,4}},{{5,6}, {7,8}}};
    std::cout << arrnNums4[1][1][1] << "\n"; //2nd page, 2nd col, 2nd row
    
 
 
// Use VECTORS when you don't know how big your arrays may be (they are resizable)   
    // Create an integer vector with 2 spaces to start
    std::vector<std::int> vecnRandNums (2);
    
    // Add values 
    vecnRandNums[0] = 10;
    vecnRandNums[1] = 20;
    
    // Add another value to the vector - appends 30 to the end of vector
    vecnRandNums.push_back(30);
    
    // Get size of vector
    std::cout << "Vector Size : " << vecnRandNums.size() << "\n";
    
    // Get last value
    std::cout << "Last Index : " << vecnRandNums[vecnRandNums.size() - 1] << "\n";
    
    // Convert a string into an array
    std::string sSentence = "This is a random string";
    
    // Create a vector
    std::vector<std::string> vecsWords;
    
    // A stringstream object receives strings separated by a space & spits them out 1 by 1
    std::stringstream ss(sSentence);
    
    // Will temporarily hold each word in the string
    std::string sIndivStr;
    
    // Defines what separates the words
    char cSpace = ' ';
    
    // While there are more words to extract keep
    // executing
    // getline takes strings from a stream of words stored
    // in the stream and each time it finds a blanks space
    // it stores the word proceeding the space in sIndivStr
    while(getline(ss, sIndivStr, cSpace)){
        
        // Put the string into a vector
        vecsWords.push_back(sIndivStr);
    }
    
    // Cycle through each index in the vector and print
    // out each word 
    for(int i = 0; i < vecsWords.size(); ++i){
        std::cout << vecsWords[i] << "\n";
    }
    
    return 0;
}
 
