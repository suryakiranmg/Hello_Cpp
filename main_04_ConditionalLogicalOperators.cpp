// ----- CONDITIONAL OPERATORS -----
    // Conditional operators help you to perform
    // different actions depending on conditions
    // ==, !=, <, >, <=, >=
    
    // ----- LOGICAL OPERATORS -----
    // Logical operators allow you to combine conditions
    // && : If both are true it returns true
    // || : If either are true it returns true
    // ! : Converts true into false and vice versa
 
    // ----- EXAMPLE : IS A BIRTHDAY IMPORTANT -----
    // 1 - 18, 21, 50, > 65 : Important
    // All others are not important
    
    std::string sAge = "0";
    std::cout << "Enter your age : ";
    getline(std::cin, sAge);
    int nAge = std::stoi(sAge);
    
    // if and else is used to execute different code
    // depending on conditions
    if ((nAge >= 1) && (nAge <= 18)){
        std::cout << "Important Birthday\n";
    } else if ((nAge == 21) || (nAge == 50)) {
        std::cout << "Important Birthday\n";
    } else if (nAge >= 65){
        std::cout << "Important Birthday\n";
    } else {
        std::cout << "Not an Important Birthday\n";
    }
    // ----- END EXAMPLE : IS A BIRTHDAY IMPORTANT ——
 
// ----- PROBLEM : DETERMINE SCHOOL GRADE -----
    // If age 5 "Go to Kindergarten"
    // Ages 6 through 17 go to grades 1 through 12
    // If age > 17 "Go to college"
    // Enter age : 2
    // Too young for school
    // Enter age : 8
    // Go to grade 3
    // Try to do with 15 or less lines of code
    
    std::string sAge = "0";
    int nGrade = 0;
    std::cout << "Enter age : ";
    getline(std::cin, sAge);
    int nAge = std::stoi(sAge);
    
    if (nAge < 5)
        std::cout << "To young for school\n";
    else if (nAge == 5)
        std::cout << "Go to Kindergarten\n";
    else if ((nAge > 5) && (nAge <= 17)){
        nGrade = nAge - 5;
        std::cout << "Go to grade " << nGrade << "\n";
    } else
        std::cout << "Go to college\n";
        
    // ----- END PROBLEM : DETERMINE SCHOOL GRADE -----
