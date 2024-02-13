// Maximum sum of non - adjacent elements
#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &arr, int i, int sum, int &maxi)
{
    // base case
    if (i >= arr.size())
    {
        maxi = max(sum, maxi);
        return;
    }

    // include
    solve(arr, i + 2, sum + arr[i], maxi);

    // exclude
    solve(arr, i + 1, sum, maxi);
}

int main()
{
    vector<int> arr{2, 3, 5, 1};

    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;

    solve(arr, i, sum, maxi);

    cout << maxi << endl;

    return 0;
}