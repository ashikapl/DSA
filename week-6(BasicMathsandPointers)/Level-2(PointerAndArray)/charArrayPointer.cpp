#include <iostream>
using namespace std;

int main()
{
    // char ch[10] = "Babbar";
    // char *c = ch;

    // cout << ch << endl; // here ch, &ch[0] and c is storing full string of char array
    // cout << &ch << endl;
    // cout << *c << endl;
    // cout << &ch[0] << endl;
    // cout << c << endl;
    // cout << ch[0] << endl; // *c and ch[0] has store same element but c is store address of element

    char chr = 'k';
    char *ptr = &chr;

    cout << chr << endl;
    cout << &chr << endl; // after k &chr and ptr show default value
    cout << ptr << endl;
    cout << &ptr << endl;
    cout << *ptr << endl;

    return 0;
}