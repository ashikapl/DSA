// Eko-Spoj problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<long long int> trees, long long int m, long long int mid)
{
    long long int woodCollect = 0;

    for (long long int i = 0; i < trees.size(); i++)
    {
        if (trees[i] > mid)
        {
            woodCollect += trees[i] - mid;
        }
    }

    return woodCollect >= m;
}

long long int maxSawblade(vector<long long int> trees, long long int m)
{
    long long int start = 0;
    long long int end = *max_element(trees.begin(), trees.end());
    long long int ans = -1;

    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;

        if (isPossible(trees, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    long long int n, m;
    cout << "Enter the size of array and how many metres of wood required:- ";
    cin >> n >> m;

    vector<long long int> trees;
    cout << "Enter the height of trees:- ";
    while (n--)
    {
        long long int height;
        // cout << "Enter the height of trees:- ";
        cin >> height;
        trees.push_back(height);
    }

    cout << "Max height of Sawblade is:- " << maxSawblade(trees, m) << endl;

    return 0;
}