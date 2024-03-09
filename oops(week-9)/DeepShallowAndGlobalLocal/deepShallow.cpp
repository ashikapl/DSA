// Deep and Shallow Copy
#include <iostream>
using namespace std;

class abc
{
public:
    int x;
    int *y;

    // Inilialization list
    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // default dumb copy constructor -> for Shallow copy
    // abc(const abc &obj) // here both the objects are locate at same memory loaction
    // {
    //     x = obj.x;
    //     y = obj.y;
    // }

    // copy constructor made by ourself -> is Deep copy
    abc(const abc &obj) // here both the object are locate at different memory location
    {
        x = obj.x;
        y = new int(*obj.y);
    }

    void print() const
    {
        cout << "X -> " << x << endl;
        cout << "Y Pointer address -> " << y << endl;
        cout << "Y -> " << *y << endl;
        cout << endl;
    }
};

int main()
{
    abc a(1, 2); // when same memory address then it is shallow copy with Default copy constructor
    cout << "Priting for a" << endl;
    a.print();

    // abc b(a);
    abc b = a;
    cout << "Priting for b" << endl;
    b.print();

    return 0;
}