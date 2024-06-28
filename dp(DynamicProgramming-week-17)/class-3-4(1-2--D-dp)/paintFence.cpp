// Painting the fenchesss... Using Recursion, Memoisation, Tabulation and Space Optimization
// TC -> O(2^n) to O(n) from recursion to tabulation
// SC -> O(n) to O(1) from recursion to space optimization
#include<iostream>
#include<vector>
using namespace std;

// Recursive Approach
int paintFenceUsingRecursion(int n, int k)
{  
    // base case
    if(n == 1) return k;
    if(n == 2) return (k + k * (k-1));

    int ans = (paintFenceUsingRecursion(n-2,k) + paintFenceUsingRecursion(n-1,k)) * (k-1);
    return ans;
}

// Memoisation Approach
int paintFenceUsingMemoisation(int n, int k, vector<int>& dp)
{
    // base case
    if(n == 1) return k;
    if(n == 2) return (k + k * (k-1));
    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (paintFenceUsingMemoisation(n-2,k,dp) + paintFenceUsingMemoisation(n-1,k,dp)) * (k-1);
    return dp[n];
}

// Tabulation Approach
int paintFenchUsingTab(int n, int k)
{
    vector<int> dp(n+1,0);
    dp[1] = k;
    dp[2] = (k + k * (k-1));

    for(int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i-2] + dp[i-1]) * (k-1);
    }
    return dp[n];
}

// Space Optimization
int paintFenchUsingSpaceOpti(int n, int k)
{
    int prev2 = k;
    int prev1 = (k + k * (k-1));

    for(int i = 3; i <= n; i++)
    {
        int curr = (prev2 + prev1) * (k-1);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n = 2;
    int k = 4;

    // int ans = paintFenceUsingRecursion(n,k);

    // vector<int> dp(n+1,-1);
    // int ans = paintFenceUsingMemoisation(n,k,dp);

    int ans = paintFenchUsingTab(n,k);
    cout << "Ans: " << ans << endl;

    return 0;
}