// Reverse the string
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

void reverseCharArray(char ch[])
{
    int i = 0;
    int n = getLength(ch);
    int j = n - 1;

    while (i <= j)
    {
        swap(ch[i], ch[j]);
        i++;
        j--;
    }
}

int main()
{
    char ch[100];
    cin >> ch;

    cout << "Length of string:- " << getLength(ch) << endl;
    // cout << "Length of string using pre-define funtion:- " << strlen(ch);

    cout << "Initial:- " << ch << endl;

    reverseCharArray(ch);

    cout << "After reverse:- " << ch << endl;

    return 0;
}