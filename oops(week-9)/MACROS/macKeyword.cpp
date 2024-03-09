#include <iostream>
using namespace std;

#define PI 3.14                    // constant value define as Macros for reusable
#define MAXX(x, y) (x > y ? x : y) // creating shortcut for commonly used expressions

float circleArea(float r)
{
    return PI * r * r;
}

float circlePerimeter(float r)
{
    return 2 * PI * r;
}

void fun()
{
    int a = 3;
    int b = 6;
    int c = MAXX(a, b);
    cout << c << endl;
}

void fun2()
{
    int p = 7;
    int q = 5;
    int r = MAXX(p, q);
    cout << r << endl;
}

void fun3()
{
    int x = 3;
    int y = 1;
    int z = MAXX(x, y);
    cout << z << endl;
}

int main()
{
    cout << circleArea(4.5) << endl;
    cout << circlePerimeter(2.3) << endl;
    fun();
    fun2();
    fun3();

    return 0;
}