#include <iostream>
using namespace std;

int main()
{
    char name[10] = "SherBano";
    char *c = name;

    cout << name << endl;        // SherBano
    cout << &name << endl;       // Base address - first element address
    cout << *(name + 3) << endl; // r
    cout << c << endl;           // SherBano
    cout << &c << endl;          // address of c
    cout << *(c + 3) << endl;    // r
    cout << c + 2 << endl;       // erBano
    cout << *c << endl;          // S
    cout << c + 8 << endl;       // out of bound means null character array length is over

    return 0;
}