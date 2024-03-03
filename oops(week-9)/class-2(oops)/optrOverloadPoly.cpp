// Operator Overloading -> Compile time polymorphsim concept
#include <iostream>
using namespace std;

class Parameter
{

public:
    int val;

    // operator Overloading function
    void operator+(Parameter &object2)
    {
        int value1 = this->val;
        int value2 = object2.val;

        cout << (value2 - value1) << endl;
    }
};

int main()
{
    Parameter object1, object2;

    object1.val = 2;
    object2.val = 8;

    // we should find the difference btwn this two objects val with the help of (+) sign
    // here object 1 is a current parameter value
    object1 + object2;

    return 0;
}