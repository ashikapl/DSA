// Class data members and functions can be constant
#include <iostream>
using namespace std;

class A
{
    int x;
    int *y;
    const int z;

public:
    // constructor -> old style

    // A(int _x, int _y, int _z = 0) // here _z is default argument
    // {
    //     x = _x;
    //     y = new int(_y);
    //     z = _z;
    // }

    // new style Constructor -> initailization list
    A(int _x, int _y, int _z = 0) : x(_x), y(new int(_y)), z(_z) // here we can initailize const variable
    {
        cout << "I am in initialisation list" << endl;
    }

    int getX() const // if here we put const then the value of x can't be change
    {
        // x = 5; -> show error
        return x;
    }
    void setX(int _x)
    {
        x = _x;
    }

    int getY() const // if here we put const then the value of *y can't be change
    {
        // y = 5; -> show error
        return *y;
    }
    void setY(int _y)
    {
        *y = _y;
    }

    int getZ() const // if we don't make this function const then it show error can't print values
    {
        return z;
    }
};

void printA(const A &obj) // this function takes only const variable
{
    cout << obj.getX() << " " << obj.getY() << " " << obj.getZ() << endl;
}

int main()
{
    A obj(11, 2, 3);

    printA(obj);

    return 0;
}