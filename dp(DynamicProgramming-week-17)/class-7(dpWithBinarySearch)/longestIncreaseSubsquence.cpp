// Longest Increasing Subsquence (leetcode-300) using recursion,memoisation,tabulation,
// and space optimize and then solve using binary search
// TC -> O(2^n) to O(nlogn) from recursion to binary search after space optimize
// SC -> O(n*n) to O(n) from recursion to space optimization
#include<iostream>
#include<vector>
using namespace std;

// Recursive Approach
int LISUsingRecursion(vector<int>& arr, int n, int curr, int prev)
{
    // base case
    if(curr >= n) return 0;

    int include = 0;
    if(prev == -1 || arr[curr] > arr[prev])
    {
        include = 1 + LISUsingRecursion(arr,n,curr+1,curr);
    }

    int exclude = 0 + LISUsingRecursion(arr,n,curr+1,prev);

    int ans = max(include,exclude);
    return ans;
}

// Using Memoisation Approach
int LISUsingRecursion(vector<int>& arr, int n, int curr, int prev, vector<vector<int>> &dp)
{
    // base case
    if(curr >= n) return 0;
    if(dp[curr][prev+1] != -1)
    {
        return dp[curr][prev+1];
    }

    int include = 0;
    if(prev == -1 || arr[curr] > arr[prev])
    {
        include = 1 + LISUsingRecursion(arr,n,curr+1,curr,dp);
    }

    int exclude = 0 + LISUsingRecursion(arr,n,curr+1,prev,dp);

    dp[curr][prev+1] = max(include,exclude);
    return dp[curr][prev+1];
}

// using Tabulation Approach
int LISUsingTab(vector<int>& arr, int n)
{
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

    for(int curr = n-1; curr >= 0; curr--)
    {
        for(int prev = curr-1; prev >= -1; prev--)
        {
            int include = 0;
            if(prev == -1 || arr[curr] > arr[prev])
            {
                include = 1 + dp[curr+1][curr+1];
            }

            int exclude = 0 + dp[curr+1][prev+1];

            dp[curr][prev+1] = max(include,exclude);
        }
    }

    return dp[0][0];
}

// using space optimization
int LISUsingSpaceOpti(vector<int>& arr, int n )
{
    if(n == 0) return 0;
    vector<int> currRow(n+1,0);
    vector<int> nextRow(n+1,0);

    for(int curr = n-1; curr >= 0; curr--)
    {
        for(int prev = curr-1; prev >= -1; prev--)
        {
            int include = 0;
            if(prev == -1 || arr[curr] > arr[prev])
            {
                include = 1 + nextRow[curr+1];
            }
            int exclude = 0 + nextRow[prev+1];

            currRow[prev+1] = max(include,exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

// Further more space opimtize the code
int LISUsingSO2(vector<int>& arr, int n)
{
    if(arr.size() == 0) return 0;
    
    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > ans.back())
        {
            ans.push_back(arr[i]);
        }
        else
        {
            // curr se just choti value ans array mein find it and replace with the curr value
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }
    return ans.size();
}

int main()
{
    vector<int> arr{0,1,0,3,2,3};
    int n = arr.size();

    // int curr = 0; // here curr represent the curr index no.
    // int prev = -1; // here prev represent the curr element before element value index
    // int ans = LISUsingRecursion(arr,n,curr,prev); // LIS -> longest Increase Subsquence

    // vector<vector<int> > dp(n, vector<int>(n,-1));
    // int ans = LISUsingRecursion(arr,n,curr,prev,dp);

    // int ans = LISUsingTab(arr,n);

    // int ans = LISUsingSpaceOpti(arr,n);
    int ans = LISUsingSO2(arr,n);

    cout << "Longest Increase Subsquence length is:: " << ans << endl;

    return 0;
}