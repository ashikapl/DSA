// Find the Square Root of the element using Binary-Search //
#include <iostream>
using namespace std;

int findSqrtRoot(int n, int target)
{
    int s = 0;
    int e = n;
    int mid = s + (e - s) / 2;

    int ans = -1;

    while (s <= e)
    {
        if (mid * mid == target)
        {
            return mid;
        }
        else if (mid * mid > target)
        {
            // search in left
            e = mid - 1;
        }
        else
        {
            // store ans
            ans = mid;
            // search in right
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number:-> ";
    cin >> n;

    int target = n;

    int ans = findSqrtRoot(n, target);

    cout << "Ans is:-> " << ans << endl;

    // in point value
    int precision;
    cout << "Enter the floating digit you want:-> ";
    cin >> precision;

    double step = 0.1;
    double finalAns = ans;

    for (int i = 0; i <= precision; i++)
    {
        for (double j = finalAns; j * j <= n; j = j + step)
        {
            finalAns = j;
        }
        step = step / 10;
    }

    cout << "Final Ans in floating value is:-> " << finalAns;

    return 0;
}