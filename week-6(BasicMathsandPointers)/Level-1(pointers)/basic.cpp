#include <iostream>
using namespace std;

int main()
{
    // check address of a
    int a = 6;
    cout << &a << endl; // & this is address of operator which show address of varible where it is stored in memory//

    // create pointer
    int b = 5;
    int *ptr = &b; // pointer store the address of a

    cout << ptr << endl;

    // access the value of p pointing to
    int c = 3;
    int *p = &c;

    cout << "Value of c:- " << c << endl;
    cout << "Address of c stored in p:- " << p << endl;
    cout << "Location of c address stored in p:- " << *p << endl; // *p is also called derefernce operator

    // size of pointer p
    cout << "Size of p:- " << sizeof(p) << endl; // size of pointer is same in any datatype eg- int, float , double , bool etc;

    bool d = 0;
    bool *dtr = &d;

    cout << "value of d:- " << *dtr << endl;
    cout << "Size of dtr:- " << sizeof(dtr) << endl;

    // Bad Practice
    int *ptrs;
    cout << "Bad practice:- " << ptrs << endl;

    // Null Pointer always initialize with 0 or nullptr
    int *atr = 0;
    cout << "Null pointer:- " << atr << endl;

    return 0;
}