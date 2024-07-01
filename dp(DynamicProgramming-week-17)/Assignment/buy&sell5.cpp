// Best time to buy & sell - (5) similar to (buy&sell2) Here we can buy & sell multiple times b
// but we have to pay fee for trasactions
// Using Recursion, Memoisation, Tabulation & space Optimize
// TC -> O(2^n) to O(n) from recursion to tab or so
// SC -> O(n) to O(1) from recursion to spaceOpti

#include<iostream>
#include<vector>
using namespace std;

// solve using recursion
int buySellUsingRecursion(vector<int>& prices, int n, int i, int buy, int& fee)
{
    // base case
    if(i >= n) return 0;

    int profit = 0;
    if(buy)
    {
        int buyProfit = -prices[i] + buySellUsingRecursion(prices,n,i+1,0,fee);
        int skipBuy = buySellUsingRecursion(prices,n,i+1,1,fee);
        profit = max(buyProfit,skipBuy);
    }
    else
    {
        int sellProfit = prices[i] + buySellUsingRecursion(prices,n,i+1,1,fee) - fee;
        int skipSell = buySellUsingRecursion(prices,n,i+1,0,fee);
        profit = max(sellProfit,skipSell);
    }
    
    return profit;
}
 
// solve using memoisation (dp) - topDown
int buySellUsingMem(vector<int>& prices, int n, int i, int buy, vector<vector<int> >& dp, int&fee)
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
        int buyProfit = -prices[i] + buySellUsingMem(prices,n,i+1,0,dp,fee);
        int skipBuy = buySellUsingMem(prices,n,i+1,1,dp,fee);
        profit = max(buyProfit,skipBuy);
    }
    else
    {
        int sellProfit = prices[i] + buySellUsingMem(prices,n,i+1,1,dp,fee) - fee;
        int skipSell = buySellUsingMem(prices,n,i+1,0,dp,fee);
        profit = max(sellProfit,skipSell);
    }
    dp[i][buy] = profit;
    
    return dp[i][buy];
}

// Solve using Tabulation -bottom up
int buySellUsingTab(vector<int>& prices, int n, int& fee)
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
                int sellProfit = prices[i] + dp[i+1][1] - fee;
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
int buySellUsingSpaceOpti(vector<int>& prices, int n, int& fee)
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
                int sellProfit = prices[i] + dp[1][1] - fee;
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
    vector<int> prices{1,3,2,8,4,9};
    int n = prices.size();
    int fee = 2;

    // int ans = buySellUsingRecursion(prices,n,0,true,fee);

    // vector<vector<int> > dp(n, vector<int>(2,-1));
    // int ans = buySellUsingMem(prices,n,0,true,dp,fee);

    // int ans = buySellUsingTab(prices,n,fee);

    int ans = buySellUsingSpaceOpti(prices,n,fee);

    cout << "Maximum Profit is:: " << ans << endl;

    return 0;
}
