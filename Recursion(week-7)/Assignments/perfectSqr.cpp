// Sum of Perfect Square
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int perfectSqr(int n)
{
    // base case
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(n);

    while (i <= end)
    {
        int perfect_square = i * i;
        int numOf_perfectSquare = 1 + perfectSqr(n - perfect_square);
        if (numOf_perfectSquare < ans)
        {
            ans = numOf_perfectSquare;
        }
        ++i;
    }
    return ans;
}

int main()
{
    int n = 12;

    int ans = perfectSqr(n) - 1;

    cout << ans << endl;

    return 0;
}