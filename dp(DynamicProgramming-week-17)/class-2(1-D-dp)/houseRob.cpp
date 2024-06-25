// House Robber Problem using recursion, memoisation, tabulation, and space Optimization Approach
#include<iostream>
#include<vector>
using namespace std;

// Recursion -> T.C ->[O(2^n)] && S.C ->[O(n+n)]
int solveUsingRecursion(vector<int>& nums, int n)
{
    if(n < 0) return 0;
    if(n == 0) return nums[0];

    //include
    int include = solveUsingRecursion(nums,n-2) + nums[n];
    //exclude
    int exclude = solveUsingRecursion(nums,n-1) + 0;

    return max(include,exclude);
}

// Memoisation -> T.C ->[O(n)] && S.C ->[O(n+n)]
int solveUsingMemo(vector<int>& nums, int n, vector<int>& dp)
{
    if(n < 0) return 0;
    if(n == 0) return nums[0];
        
    if(dp[n] != -1)
    {
     return dp[n];
    }
    //include
    int include = solveUsingMemo(nums,n-2,dp) + nums[n];
    // exclude
    int exclude = solveUsingMemo(nums,n-1,dp) + 0;

    dp[n] = max(include,exclude);
    return dp[n];
}

// Tabulation -> T.C ->[O(n)] && S.C ->[O(n+n)]
int solveUsingTabulation(vector<int>& nums, int n)
{
    vector<int> dp(n+1,0);
    dp[0] = nums[0];

    for(int i = 1; i <= n; i++)
    {
        int temp = 0;
        if(i - 2 >= 0)
        {
            temp = dp[i-2];
        } 
        int include = temp + nums[i];
        int exclude = dp[i-1] + 0;

        dp[i] = max(include,exclude);
    }

    return dp[n];
}
// Space Optimization -> T.C ->[O(n)] && S.C ->[O(1)]
int solveUsingSpaceOpti(vector<int>& nums, int n)
{
    int prev2 = 0;
    int prev1 = nums[0];
    int curr = 0;

     for(int i = 1; i <= n; i++)
     {
        int temp = 0;
        if(i - 2 >= 0)
        {
            temp = prev2;
        }

        int include = temp + nums[i];
        int exclude = prev1 + 0;

        curr = max(include,exclude);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    int n = nums.size() - 1;
    cout << "Using-Recursion: " << solveUsingRecursion(nums,n) << endl;

    // memoisation
    vector<int> dp(n+1,-1);
    cout << "Using-Memoisation: " << solveUsingMemo(nums,n,dp) << endl;

    // tabulation 
    cout << "Using-Tabulation: " << solveUsingTabulation(nums,n) << endl;

    // space optimization
    cout << "Using-Space-Optimization: " << solveUsingSpaceOpti(nums,n) << endl;

    return 0;
}