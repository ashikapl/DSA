// Swap the values

#include <iostream>
#include <string.h> // this header file is include for memset function
using namespace std;

int main()
{
    int a = 2;
    int b = 8;

    cout << "Before swap the value of a and b is: " << a << " " << b << endl;

    swap(a, b);

    cout
        << "After swap the value of a and b is: " << a << " " << b;

    // char str[] = "Hello, India";
    // cout << str << endl;

    // memset(str, 'A', 5);
    // cout << str;

    return 0;
}