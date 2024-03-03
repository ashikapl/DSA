// Function Overloading -> {Compile-Time Polymorphism concept}
#include <iostream>
using namespace std;

class Maths
{
public:
    // Member Function
    // same name but different parameters with different datatypes -> function Overloading
    int sum(int a, int b)
    {
        cout << "I am in First Signature" << endl;
        return a + b;
    }

    int sum(int a, int b, int c)
    {
        cout << "I am in Second Signature" << endl;
        return a + b + c;
    }

    float sum(int a, float b)
    {
        cout << "I am in Third Signature" << endl;
        return a + b + 10;
    }
};

int main()
{
    Maths obj;
    cout << obj.sum(2, 4.3f) << endl; // to access float -> we have to write (f) after the value
    return 0;
}