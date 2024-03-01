// constructor

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

    // Constructor -> same as class name , member function, no return type
    // default constructor -> no argument
    // Constructor is used to inilialize value
    student()
    {
        this->age = 17;
        cout << "Default Constructor calls" << endl;
    }

    // paramerized constructor
    // student(string name)
    // {
    //     this->name = name;
    //     cout << "Parameterized Constructor calls" << endl;
    // }

    // paramerized constructor with 2 argument
    student(int age, string name)
    {
        this->age = age;
        this->name = name;
        cout << "paramerized constructor with 2 argument " << endl;
    }

    // Copy Constructor
    student(student &obj) // in copy constructor value pass by reference
    {
        this->age = obj.age;
        this->name = obj.name;
        cout << "Copy Constructor calls" << endl;
    }

    // method or function or behaviour
    void study()
    {
        cout << "Good in studies" << endl;
    }

    void print()
    {
        cout << this->age << " " << this->name << endl;
    }
};

int main()
{
    // static
    cout << "For Static --> " << endl;
    student sanju(12, "hema");
    // sanju.age = 17;

    // cout << "sanju's age " << sanju.age << endl;
    cout << "sanju's name " << sanju.name << endl;

    // dynamic
    cout << "For Dynamic --> " << endl;
    student *gungun = new student(10, "niharika");
    // gungun->age = 18;

    // cout << "gungun's age " << gungun->age << endl;
    cout << "gungun's name " << gungun->name << endl;

    gungun->study();

    // static for copy constructor
    student a;
    a.age = 14;
    a.name = "nidhi";
    student b = a;

    a.print();
    b.print();

    return 0;
}