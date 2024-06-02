// Sqrt Approach - prime Number // Time complexity = 0(n/2) squareRoot of n
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    int sqrtN = sqrt(n);
    // cout << sqrtN << endl;

    for (int i = 2; i <= sqrtN; i++) // loop end on squareRoot of n
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
    cout << "Enter the digit:- ";
    cin >> n;

    isPrime(n);

    if (isPrime(n) == true)
    {
        cout << "Prime" << endl;
    }
    else
    {
        cout << "Not prime" << endl;
    }

    return 0;
}