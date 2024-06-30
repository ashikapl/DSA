// Best time to buy & sell - (2) Using Recursion, Memoisation, Tabulation & space Optimize
// TC -> O(2^n) to O(n) from recursion to tab or so
// SC -> O(n) to O(1) from recursion to spaceOpti
#include<iostream>
#include<vector>
using namespace std;

// solve using recursion
int buySellUsingRecursion(int prices[], int n, int i, int buy)
{
    // base case
    if(i >= n) return 0;

    int profit = 0;
    if(buy)
    {
        int buyProfit = -prices[i] + buySellUsingRecursion(prices,n,i+1,0);
        int skipBuy = buySellUsingRecursion(prices,n,i+1,1);
        profit = max(buyProfit,skipBuy);
    }
    else
    {
        int sellProfit = prices[i] + buySellUsingRecursion(prices,n,i+1,1);
        int skipSell = buySellUsingRecursion(prices,n,i+1,0);
        profit = max(sellProfit,skipSell);
    }
    
    return profit;
}
 
// solve using memoisation (dp) - topDown
int buySellUsingMem(int prices[], int n, int i, int buy, vector<vector<int> >& dp)
{
    // base case
    if(i >= n) return 0;

    if(dp[i][buy] != -1)
    {
        return dp[i][buy];
    }

    int profit = 0;
    if(buy)
    {
        int buyProfit = -prices[i] + buySellUsingMem(prices,n,i+1,0,dp);
        int skipBuy = buySellUsingMem(prices,n,i+1,1,dp);
        profit = max(buyProfit,skipBuy);
    }
    else
    {
        int sellProfit = prices[i] + buySellUsingMem(prices,n,i+1,1,dp);
        int skipSell = buySellUsingMem(prices,n,i+1,0,dp);
        profit = max(sellProfit,skipSell);
    }
    dp[i][buy] = profit;
    
    return dp[i][buy];
}

// Solve using Tabulation -bottom up
int buySellUsingTab(int prices[], int n)
{
    vector<vector<int> >dp(n+1, vector<int>(2, 0));

    for(int i = n-1; i >= 0; i--)
    {
        for(int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if(buy)
            {
                int buyProfit = -prices[i] + dp[i+1][0];
                int skipBuy = dp[i+1][1];
                profit = max(buyProfit,skipBuy);
            }
            else
            {
                int sellProfit = prices[i] + dp[i+1][1];
                int skipSell = dp[i+1][0];
                profit = max(sellProfit,skipSell);
            }

            dp[i][buy] = profit;
        }
    }

    return dp[0][1];
}

// Solve using Space Optimization
// By using only two (2*2) matrix solve this question 
// at once then update the row value for calling another two (2*2) matrix and so on.....
// with the help of solving 2*2 matrix less space is used and easy solution
int buySellUsingSpaceOpti(int prices[], int n)
{
    vector<vector<int> >dp(n+1, vector<int>(2, 0));

    for(int i = n-1; i >= 0; i--)
    {
        for(int buy = 0; buy < 2; buy++)
        {
            int profit = 0;
            if(buy)
            {
                int buyProfit = -prices[i] + dp[1][0];
                int skipBuy = dp[1][1];
                profit = max(buyProfit,skipBuy);
            }
            else
            {
                int sellProfit = prices[i] + dp[1][1];
                int skipSell = dp[1][0];
                profit = max(sellProfit,skipSell);
            }

            dp[0][buy] = profit;
        }
        dp[1] = dp[0];
    }

    return dp[0][1];
}


int main()
{
    int prices[] = {1,2,3,4,5};
    int n = 5;

    // int ans = buySellUsingRecursion(prices,n,0,true);

    // vector<vector<int> > dp(n, vector<int>(2,-1));
    // int ans = buySellUsingMem(prices,n,0,true,dp);

    // int ans = buySellUsingTab(prices,n);

    int ans = buySellUsingSpaceOpti(prices,n);

    cout << "Maximum Profit is:: " << ans << endl;

    return 0;
}
