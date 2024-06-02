// divide 2 number using Binary search and find the quotient //
#include <iostream>
using namespace std;

int findQuotient(int dividend, int divisor)
{
    int s = 0;
    int e = abs(dividend);
    // int mid = s + (e - s) / 2;

    // if (dividend == 0 && divisor == 0)
    // {
    //     return "Not-defined!";
    // }
    // else if (dividend == 0 && divisor != 0)
    // {
    //     return "Not-defined!";
    // }
    // else
    // {
    //     return "Not-defined!";
    // }

    int ans = 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (dividend == 0 && divisor == 0)
        {
            cout << "Not-defined!" << endl;
            break;
        }
        else if (dividend == 0 && divisor != 0)
        {
            cout << "Infinite!" << endl;
            break;
        }
        else if (abs(mid * divisor) == abs(dividend))
        {
            ans = mid;
            break;
        }
        else if (abs(mid * divisor) >= abs(dividend))
        {
            // left search
            e = mid - 1;
        }
        else if (abs(mid * divisor) <= abs(dividend))
        {
            // ans store
            ans = mid;

            // right search
            s = mid + 1;
        }
        else
        {
            cout << "Wrong value!";
        }
        // int mid = s + (e - s) / 2;
    }

    // this if and else is used for -ve and +ve sign
    if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
    {
        return ans;
    }
    else
    {
        return -ans;
    }
}

int main()
{
    int dividend = 0;
    int divisor = 0;

    int ans = findQuotient(dividend, divisor);

    cout << "The quotient is--> " << ans << endl;

    // decimal value
    int precision;
    cout << "Enter the value you want after decimal:- ";
    cin >> precision;

    double step = 0.1;
    double finalAns = ans;

    for (int i = 0; i <= precision; i++)
    {
        for (double j = finalAns; j * divisor <= dividend; j = j + step)
        {
            finalAns = j;
        }
        step = step / 10;
    }

    cout << "The floating value of quotient:-> " << finalAns << endl;

    return 0;
}