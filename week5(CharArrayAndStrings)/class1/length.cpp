// find the length of string or element placed in char array
#include <iostream>
#include <cstring>
using namespace std;

int getLength(char ch[])
{
    int length = 0;
    int i = 0;

    while (ch[i] != '\0')
    {
        length++;
        i++;
    }

    return length;
}

int main()
{
    char ch[100];
    cin >> ch;

    cout << "Length of string:- " << getLength(ch) << endl;
    cout << "Length of string using pre-define funtion:- " << strlen(ch);

    return 0;
}