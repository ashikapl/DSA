// Single Inheritance -> one parent class and one child class
#include <iostream>
using namespace std;

class A
{
public:
    int age;

    // constructor
    A()
    {
        age = 14;
    }
};

class B : public A
{
public:
    void print()
    {
        cout << this->age;
    }
};

int main()
{
    B obj;

    obj.print();

    return 0;
}