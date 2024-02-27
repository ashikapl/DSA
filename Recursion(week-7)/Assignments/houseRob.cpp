// House Robber using recursion
#include <iostream>
#include <vector>
using namespace std;

int houseRob(vector<int> &num, int i)
{
    // base case
    if (i >= num.size())
    {
        return 0;
    }

    // solve 1 case
    int robAmt1 = num[i] + houseRob(num, i + 2);
    int robAmt2 = 0 + houseRob(num, i + 1);

    return max(robAmt1, robAmt2);
}

int main()
{
    vector<int> num{2, 1, 4, 2};

    int ans = houseRob(num, 0);

    cout << ans << endl;

    return 0;
}