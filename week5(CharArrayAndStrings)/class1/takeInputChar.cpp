// How to take input in char Array
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    // we can take input without using loop in char Array or sarre elements ek hi bar mein le skte he
    char ch[50];
    cout << "Enter all the character:- ";

    // for (int i = 0; i < 10; i++)
    // {
    //     cin >> ch[i];
    // }

    cin >> ch;

    cout << "My name is:- " << ch << endl;

    // take input of single element

    ch[0] = 'a';
    ch[1] = 'b';

    cout << "Enter the element:- ";
    // cin.getline(ch, 50);// this funtion is used to take input in space and show output also in space
    cin >> ch[3];

    cout << ch[0] << ch[1] << ch[3];

    return 0;
}