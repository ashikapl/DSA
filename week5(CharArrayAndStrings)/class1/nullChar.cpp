// null character is store when the string is over
#include <iostream>
using namespace std;

int main()
{
    char ch[10];
    cin >> ch;

    cout << "mera naam " << ch << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << "Index: " << i << " value " << ch[i] << endl;
    }
    cout << endl;

    int value = (int)ch[6];

    cout << "value of 6th index " << value;
}