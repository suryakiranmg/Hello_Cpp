// ---------- C++ TUTORIAL 8 ----------
 
// Add this to Project Properties -std=c++14
 
// ---------- BUBBLE SORT ----------
 
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <ctime>
#include <cmath>
 
std::vector<int> GenerateRandVec(int numOfNums,
        int min, int max);
 
void BubbleSort(std::vector<int>& theVec);
 
int main() {
    
    // Generate a random vector of 10 values between 1 and 50
    std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
    
    BubbleSort(vecVals);
    
    // Output the sorted vector
    for(auto x: vecVals)
        std::cout << x << "\n";
    
    return 0;
    
}
 
std::vector<int> GenerateRandVec(int numOfNums,
        int min, int max){
    std::vector<int> vecValues;
    
    // Seed the random number generator
    srand(time(NULL));
    
    int i = 0, randVal = 0;
    
    while(i < numOfNums){
        // The min added on increases result based on min
        // The remainder of modulus can't be greater
        // then the divisor. We have to adjust down
        // based on the addition from min
        randVal = min + std::rand() % ((max + 1) - min);
        vecValues.push_back(randVal);
        i++;
    }
    return vecValues;
}
 
void BubbleSort(std::vector<int>& theVec){
    
    // ----- SORT A LIST : BUBBLE SORT -----
// The Bubble sort is a way to sort a list
// It works this way
// 1. An outer loop decreases in size each time
// 2. The goal is to have the largest number at 
// the end of the list when the outer loop 
// completes 1 cycle
// 3. The inner loop starts comparing indexes 
// at the beginning of the loop
// 4. Check if list[Index] > list[Index + 1]
// 5. If so swap the index values
// 6. When the inner loop completes the largest number is at
// the end of the list
// 7. Decrement the outer loop by 1
 
// Create the value that will decrement for the outer loop
// Its value is the last index in the list
    int i = theVec.size() - 1;
    
    while(i >= 1){
        int j = 0;
        
        while(j < i){
            printf("\nIs %d > %d\n", theVec[j], theVec[j + 1]);
            
            if(theVec[j] >= theVec[j+1]){
                std::cout << "Switch\n";
                
                int temp = theVec[j];
                theVec[j] = theVec[j+1];
                theVec[j+1] = temp;
            } else {
                std::cout << "Don't Switch\n";
            }
            j += 1;
            
            for(auto k: theVec){
                std::cout << k << ", ";
            }
        }
        std::cout << "\nEnd of Round\n";
        i -= 1;
    }
 
// ---------- END OF BUBBLE SORT ----------
 
// ---------- RECURSION CALCULATING FACTORIALS ----------
 
int Factorial(int number);
 
int main() {
    
    // A recursive function is one that calls itself
    // You must have an exit condition or you'll have 
    // an infinite loop
    // GetFactorial(3) = 3 * 2 * 1
    std::cout << "Factorial 3 = " << Factorial(3) << "\n";
    
    return 0;
}
 
// 1. 3 * Factorial(2) (2) = 6
// 2. 2 * Factorial(1) (1)
// 3. 1 Return 1
 
 
int Factorial(int number){
    if(number == 1){
        return 1;
    } else {
        int result = number * Factorial(number - 1);
        return result;
    }
}    
 
// ---------- END RECURSION CALCULATING FACTORIALS ----------
 
// ----- PROBLEM PRINT ARRAY HORIZONTALLY -----
 
------------------
|  0  |  1  |  2  |
------------------
| 10  |  8  |  2  |
------------------
 
void PrintHorzVector(std::vector<int>& theVec);
 
int main() {
    
    std::vector<int> theVec = {10,8,2,5,9,11,6,14};
    PrintHorzVector(theVec);
    
    return 0;
}
 
void PrintHorzVector(std::vector<int>& theVec){
    int dashes = std::ceil(theVec.size() * 6);
    
    for(int n = 0; n < dashes; n++)
        std::cout << "-";
    std::cout << "\n";
    
    for(int n = 0; n < theVec.size(); n++)
        printf("| %2d  ", n);
    std::cout << "|\n";
    
    for(int n = 0; n < dashes; n++)
        std::cout << "-";
    std::cout << "\n";
    
    for(int n = 0; n < theVec.size(); n++)
        printf("| %2d  ", theVec[n]);
    std::cout << "|\n";
    
    for(int n = 0; n < dashes; n++)
        std::cout << "-";
    std::cout << "\n";
 
}
// ----- END PROBLEM PRINT ARRAY HORIZONTALLY -----
 
// ----- PROBLEM : GENERATE FIBONACCI NUMBER -----
// Use recursion to generate the following results
// fib(0) = 0, fib(1) = 1, fib(2) = 1, fib(3) = 2,
// fib(4) = 3, fib(5) = 5, fib(6) = 8, fib(7) = 13
 
int Fib(int index);
 
int main() {
    int index;
    std::cout << "Get Fibonacci Index : ";
    std::cin >> index;
    printf("fib(%d) = %d\n", index, Fib(index));
    
    return 0;
    
}
 
int Fib(int index){
    if (index < 2){
        return index;
    } else {
        return Fib(index - 1) + Fib(index - 2);
    }
}
 
// ----- END PROBLEM : GENERATE FIBONACCI NUMBER -----
 
// ----- OVERLOADING FUNCTIONS -----
// Overloaded functions have the same names and
// return types, but have different parameters
double Area(double radius);
double Area(double height, double width);
 
int main() {
    std::cout << "Area Circle (c) or Rectangle (r) : ";
    char areaType;
    std::cin >> areaType;
    
    switch(areaType){
        case 'c' : 
            std::cout << "Enter Radius : ";
            double radius;
            std::cin >> radius;
            std::cout << "Area = " << Area(radius) << "\n";
            break;
        case 'r' : 
            std::cout << "Enter Height : ";
            double height, width;
            std::cin >> height;
            std::cout << "Enter Width : ";
            std::cin >> width;
            std::cout << "Area = " << Area(height,width) << "\n";
            break;
        default : std::cout << "Please Enter c or r\n";
    }
    return 0;
}
 
double Area(double radius){
    return 3.14159 * std::pow(radius, 2); 
}
 
double Area(double height, double width){
    return height * width;
}
