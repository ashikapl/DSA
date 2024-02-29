// number of dice roll with target sum this code show TLE becoz of Time complexity
#include <iostream>
using namespace std;

int numRollsToTarget(int n, int k, int target)
{
    //  base case
    if (n == 0 && target == 0)
        return 1;
    if (n == 0 || target == 0)
        return 0;

    // solve one case
    int ans = 0;

    for (int i = 1; i <= k; i++)
    {
        if (target - i >= 0)
        {
            ans = ans + numRollsToTarget(n - 1, k, target - i);
        }
    }

    return ans;
}

int main()
{
    int n = 3;
    int k = 2;
    int target = 6;

    int ans = numRollsToTarget(n, k, target);

    cout << ans << endl;

    return 0;
}