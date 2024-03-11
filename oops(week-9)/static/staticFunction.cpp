// Static Member Function
#include <iostream>
using namespace std;

class Rahul
{
public:
    int x, y;

    Rahul() : x(0), y(0) {}

    static void print() // there is no use of (this) pointer only static variable print in this function
    {
        // cout << x << " " << y << endl;
        cout << "I am in Static Function " << endl;
    }
};

int main()
{
    Rahul a;
    // a.x = 4; // if the member variable is non static it shows error
    // a.y = 1;
    // Rahul::x; // we can declare variables in this type also
    // Rahul::y;
    a.print();

    Rahul b;
    // b.x = 3;
    // b.= 2;
    // Rahul::x;
    // Rahul::y;
    b.print();

    return 0;
}