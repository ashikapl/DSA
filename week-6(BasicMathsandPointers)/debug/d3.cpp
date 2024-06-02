#include <iostream>
using namespace std;

int *foo()
{
    int *p = new int;
    *p = 10;
    return p;
}

int main()
{
    int *q = foo();
    cout << *q << endl; // Expected output: 10, Actual output: some random value
    return 0;
}