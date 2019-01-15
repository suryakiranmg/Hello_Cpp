#include <fstream>
# include <iostream>

using namespace std;

class Student
{
public:
    string name;
    int roll;
    string branch;
    
    
 //friend funs for IO serialisation
    friend ofstream & operator<<(ofstream &ofs, Student s);
    friend ifstream & operator>>(ifstream &ifs, Student &s);
};

//friend functions
ofstream & operator<<(ofstream &ofs, Student s)
{
    ofs<<s.name<<endl;
    ofs<<s.roll<<endl;
    ofs<<s.branch<<endl;
    return ofs;
    
}
ifstream & operator>>(ifstream &ifs, Student &s)
{
    ifs>>s.name;
    ifs>>s.roll;
    ifs>>s.branch;
    return ifs;
}

int main()
{
    Student s1;
    s1.name = "Suki";  s1.roll = 25;  s1.branch = "EE";
    ofstream ofs("Student.txt",ios::trunc);
    ofs<<s1;
    ofs.close();
    
    ifstream ifs("Student.txt");
    ifs>>s1;
    cout<<"Name: "<<s1.name<<endl;
    cout<<"Roll: "<<s1.roll<<endl;
    cout<<"Branch: "<<s1.branch<<endl;
    ifs.close();
    return 0;
    
}


 
