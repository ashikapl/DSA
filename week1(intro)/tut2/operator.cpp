#include <iostream>
using namespace std;

int main()
{

    int a = 4;
    int b = 2;

    // example of Arithmetic Operator //

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a % b << endl;
    cout << a / b << endl;
    cout << endl;

    // Relational Operator //

    // Its output will print in 0 and 1 (means if true then print 1 and if false then print 0)

    int c = 5;
    int d = 3;

    cout << (c < d) << endl;
    cout << (c > d) << endl;
    cout << (c <= d) << endl;
    cout << (c >= d) << endl;
    cout << (c != d) << endl;
    cout << (c == d) << endl;

    // Assignment Operator //

    int num = 25;
    cout << num << endl;

    // where this (=) sign is assignment Operator // when we assign a value assignment oparator is used//

    // logical Operator //

    // It is used in conditons or operations //

    // (&& || !) //

    int i = 10;
    int x = 2;

    if (i < x && i != x)
    {
        cout << "Ashika" << endl;
    }
    else if(i<x || i>x)
    {
        cout << "Akshita" << endl;
    }
    else if(!(i==x)){
        cout << "Palak" << endl;   
        
     }
    else {
        cout << "Good" << endl;
    }


}