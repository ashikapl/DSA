// Max subArray Sum
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSum(vector<int> &v, int start, int end)
{
    // base case
    if (start == end)
    {
        return v[start];
    }

    int maxLeftBorderSum = INT_MIN;
    int maxRightBorderSum = INT_MIN;

    int mid = start + (end - start) / 2;

    int maxLeftSum = maxSum(v, start, mid);
    int maxRightSum = maxSum(v, mid + 1, end);

    int leftBorderSum = 0;
    int rightBorderSum = 0;
    for (int i = mid; i >= start; i--)
    {
        leftBorderSum += v[i];
        if (leftBorderSum > maxLeftBorderSum)
        {
            maxLeftBorderSum = leftBorderSum;
        }
    }

    for (int i = mid + 1; i <= end; i++)
    {
        rightBorderSum += v[i];
        if (rightBorderSum > maxRightBorderSum)
        {
            maxRightBorderSum = rightBorderSum;
        }
    }

    // cross border sum
    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
    return max(max(maxLeftSum, maxRightSum), crossBorderSum);
}

int main()
{
    vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int ans = maxSum(v, 0, v.size() - 1);

    cout << ans << endl;

    return 0;
}