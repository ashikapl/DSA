// K- difference pair in an array (two Pointer approach)
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int findPair(vector<int> arr, int k, int n)
{
    sort(arr.begin(), arr.end());

    set<pair<int, int>> ans;
    int i = 0, j = 1;

    while (j < n)
    {
        int diff = arr[j] - arr[i];
        if (diff == k)
        {
            ans.insert({arr[i], arr[j]});
            cout << "Pairs are:--> " << arr[i] << " " << arr[j] << endl;
            ++i, ++j;
        }
        else if (diff > k)
        {
            ++i;
        }
        else if (i == j)
        {
            j++;
        }
        else
        {
            ++j;
        }
    }

    return ans.size();
}

int main()
{
    vector<int> arr{1, 3, 1, 5, 4};
    int n = arr.size();
    int k = 2;

    int ans = findPair(arr, k, n);

    cout << "Pair is:--> " << ans;

    return 0;
}

// we can also solve this problem with the help of binarysearch I try it on leetcode