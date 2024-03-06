// Basic syntax and types of const keyword
#include <iostream>
using namespace std;

int main()
{
    // const int a = 4;
    // cout << a << endl;

    // a = 8;  // here it show error becoz can't change the value of constant variable

    // 1. const with pointer

    // int const *c = new int(3);
    // const int * c = new int(3); // same mean as line no 13

    // here we can change pointer (c) value but can't change (*c) value

    // *c = 5;  // here it shows error becoz *c can't be changed
    // int b = 20;
    // c = &b; // here we can change pointer value using another variable

    // 2. Const pointer but Non-Const Data

    // here we can change variable value but can't change pointer value becoz here pointer is constant
    // int *const a = new int(5);
    // *a = 20;

    // int b = 10;
    // a = &b; // here it show error becoz pointer value is constant

    // 3. Const Pointer and Const Variable

    // here both can't change its value becoz both are constant

    const int *const a = new int(3);

    // *a = 2; // here show error
    // int n = 3;
    // a = &n; // here also show error becoz both are constand can't change

    return 0;
}