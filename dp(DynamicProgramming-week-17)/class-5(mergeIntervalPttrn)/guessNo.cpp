// Guess no higher or lower II -> (leecode-375)- Using Recursion, Memoization and Tabulation
// TC -> O(2^n) to O(n^3) form recursion to tabulation approach
// SC -> O(n^2) for all the approaches
#include<iostream>
#include<vector>
using namespace std;

// Recursion Approach
int getAmountUsingRecursion(int start, int end)
{
    // base case
    if(start >= end) return 0;

    int minAns = INT_MAX;
    for(int i = start; i <= end; i++)
    {
        // dono side left or right me se maximum amount nikal lo then add ith value
        // ith value isliye add karni hai kyuki wo ith value wrong guess ki hai
        // or wahi tumhara minimum amount of money to win the game
        minAns = min(minAns, i + max(getAmountUsingRecursion(start,i-1),getAmountUsingRecursion(i+1,end)));
    }
    return minAns;
}

// using Memoisation
int getAmountUsingMemo(int start, int end, vector<vector<int> >&dp)
{
    if(start >= end) return 0;

    if(dp[start][end] != -1)
    {
        return dp[start][end];
    }
    
    int minAns = INT_MAX;
    for(int i= start; i <= end; i++)
    {
        minAns = min(minAns, i + max(getAmountUsingMemo(start,i-1,dp),getAmountUsingMemo(i+1,end,dp)));
    }
    dp[start][end] = minAns;
    return dp[start][end];
}

// Using Tabulation
int getAmountUsingTab(int n)
{
    vector<vector<int> >dp(n+2, vector<int>(n+2, 0));

    for(int start = n; start >= 1; start--)
    {
        for(int end = 1; end <= n; end++)
        {
            if(start >= end)
            {
                continue;
            }
            else
            {
                int minAns = INT_MAX;
                for(int i= start; i <= end; i++)
                {
                    minAns = min(minAns, i + max(dp[start][i-1],dp[i+1][end]));
                }
                dp[start][end] = minAns;
            }
        }
    }
    return dp[1][n];
}

int main()
{
    int n = 10;
      
    // Using Recursion
    // int ans = getAmountUsingRecursion(1,n);

    // Using memoisation
    // vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
    // int ans = getAmountUsingMemo(1,n,dp);
    
    // Using Tabulation
    int ans = getAmountUsingTab(n);

    cout << "Minimum amount of money required to win the game:-> " << ans << endl;

    return 0;
}