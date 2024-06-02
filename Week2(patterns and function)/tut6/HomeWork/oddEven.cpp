// Find number is Even or Odd //

#include <iostream>
using namespace std;

bool checkEvenOdd(int n)
{
    if (n % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n;
    cout << "Enter the value: ";
    cin >> n;

    bool result = checkEvenOdd(n);

    if (result)
    {
        cout << n << " "
             << "is Even number.";
    }
    else
    {
        cout << n << " "
             << "is odd number.";
    }

    return 0;
}