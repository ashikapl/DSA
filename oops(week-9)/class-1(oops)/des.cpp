// Destructor
#include <iostream>
#include <string>
using namespace std;

class student
{
public:
    // state or property
    int section;
    int age;
    string name;

    // constructor -> same name as class name calls for inilialize
    student()
    {
        cout << "constructor calls" << endl;
    }

    // Destructor -> when program or function end the object automatically calls
    // destructor to destroy the function or program

    ~student()
    {
        cout << "I am destructor" << endl;
    }

    // method or function or behaviour
    void study()
    {
        cout << "Good in studies" << endl;
    }
};

int main()
{
    // static -> destructor automatically calls
    student a;

    // dynamic -> we have to delete the object by delete keyword
    student *b = new student;

    // delete keyword to destroy dynamic pointer
    delete (b);

    return 0;
}