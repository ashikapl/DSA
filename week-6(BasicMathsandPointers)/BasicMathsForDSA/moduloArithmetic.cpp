// a^b find by slow and fast two types of exponential search with different time complexity
#include <iostream>
using namespace std;

int fastExponential(int a, int b)
{
    int ans = 1;

    while (b > 0)
    {
        if (b & 1) // bitwise operator xor to find odd
        {
            // odd
            ans *= a;
        }
        a = a * a;
        b >>= 1; // b/2
    }
    return ans;
}

int slowExponential(int a, int b)
{
    int ans = 1;

    for (int i = 0; i < b; i++)
    {
        ans = ans * a;
    }

    return ans;
}

int main()
{
    int a = 2;
    int b = 7;

    cout << "Using Slow Exponential:- " << slowExponential(a, b) << endl;
    cout << "Using Fast Exponential:- " << fastExponential(a, b) << endl;

    return 0;
}