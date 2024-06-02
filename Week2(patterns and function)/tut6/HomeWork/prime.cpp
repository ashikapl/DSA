// Check prime //

#include <iostream>
using namespace std;

bool checkPrime(int n)
{
    int i = 2;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    bool result = checkPrime(n);

    if (result)
    {
        cout << n << " "
             << "is Prime";
    }
    else
    {
        cout << n << " "
             << "is Not Prime";
    }

    return 0;
}