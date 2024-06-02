#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int *p = &a;
    int **q = &p;

    cout << a << endl;   // 5
    cout << &a << endl;  // adrs of a
    cout << p << endl;   // adrs of a
    cout << &p << endl;  // adres of p
    cout << *p << endl;  // 5
    cout << q << endl;   // adrs of p
    cout << &q << endl;  // adrs of q
    cout << *q << endl;  // value store in p meand adrs of a
    cout << **q << endl; // 5

    return 0;
}