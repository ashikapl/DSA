#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    cout << n << endl;
    cout << &n << endl;

    int *p = &n;

    // *p = *p + 1;

    cout << p << endl;

    return 0;
}