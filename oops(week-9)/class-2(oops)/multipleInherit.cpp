// Multiple Inheritance -> more than one parent class and only one child class
// which can inherit both parent classes..
#include <iostream>
using namespace std;

// here A is a parent class
class A
{
public:
    int chemistry;
    int physics; // same name of data member can also possible in class it can access with the help
    // Scope Resolution operator (::) eg-> {obj.A::physics}

    // Constructor -> to inilialize values
    A()
    {
        chemistry = 90;
        physics = 100;
    }
};

// here B is also a parent class
class B
{
public:
    int physics;

    // Constructor -> to inilialize values
    B()
    {
        physics = 70;
    }
};

// here C is a child class which inherit with both the parent classes A and B
class C : public A, public B
{
public:
    int maths;

    // Constructor -> to inilialize values
    C()
    {
        maths = 80;
    }
};

int main()
{
    // creation of C class object
    C obj;

    cout << "Maths-> " << obj.maths << ", Chemistry-> " << obj.chemistry << endl;
    // if both class A and B have same type of data memeber or functions than to access with
    cout << "A Physics -> " << obj.A::physics << ", B Physics -> " << obj.B::physics << endl;

    return 0;
}