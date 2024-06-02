#include <iostream>
using namespace std;

int main()
{
    int x, y;
    x = 5;
    y = ++x * ++x;
    cout << x << y;

    y = x++ * ++x;
    cout << x << y;

    return 0;
}