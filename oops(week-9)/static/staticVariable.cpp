// Static member variable
#include <iostream>
using namespace std;

class abc
{
public:
    static int x, y;

    void print() const
    {
        // here (this) pointer is pointer to static x and y
        cout << x << " " << y << endl;
    }
};

int abc::x; // Static member variables also want to declare outside the class becoz variable takes same member location
int abc::y;

int main()
{
    abc obj1;
    obj1.x = 1;
    obj1.y = 2;
    cout << "Object 1 -> ";
    obj1.print();

    abc obj2;
    obj2.x = 10;
    obj2.y = 20;
    cout << "Object 1 -> ";
    obj1.print();
    cout << "Object 2 -> ";
    obj2.print();

    return 0;
}