// Find factorial of number //

#include <iostream>
using namespace std;

int getFactorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {

        fact = fact * i;
    }

    return fact;
}

int main()
{
    int n;
    cout << "Enter the value: ";
    cin >> n;

    long result = getFactorial(n);

    cout << "The factorial is: " << result;

    return 0;
}