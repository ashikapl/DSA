// Switch case //

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value : ";
    cin >> n;

    switch (n)
    {
    case 1:
        cout << "Ashika is here.. ";
        break;
    case 2:
        cout << "Akshita is here.. ";
        break;
    case 3:
        cout << "Palak is here.. ";
        break;

    default:
        cout << "No one is here.. ";
        break;
    }
}