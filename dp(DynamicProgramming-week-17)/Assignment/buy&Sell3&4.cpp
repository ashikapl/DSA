// Best time to buy & sell of stocks-3 at most (2) times trasactions using RE, Memoi, tabu, and SpaceOpti
// TC -> O(2^n) to O(N) from recur to space opti
// SC -> O(n^2) to O(1) from recursion to space optimisation

// Best time to buy & sell of stocks-4 is similar as stocks-3 the only condition is that there we can
// buy at most (k) times transactions
// the only change in this code is (limit = k) not (2); leetcode-188 or (gfg) have the solution 

#include<iostream>
#include<vector>
using namespace std;

// Using Recursion 
int maxProfit_RE(vector<int>& prices, int i, int buy, int limit)
{
    int n = prices.size();
    // base case
    if(i >=n || limit == 0) return 0;

    int profit = 0;
    if(buy) 
    {
        int buyProfit = -prices[i] + maxProfit_RE(prices,i+1,0,limit);
        int skipBuy = maxProfit_RE(prices,i+1,1,limit);
        profit = max(buyProfit, skipBuy);
    }
    else 
    {
        int sellProfit = prices[i] + maxProfit_RE(prices,i+1,1,limit-1);
        int skipSell = maxProfit_RE(prices,i+1,0,limit);
        profit = max(sellProfit, skipSell);
    }

    return profit;
}

// Using Memoisation - TopDown
int maxProfit_TopDown(vector<int>& prices, int i, int buy, int limit, vector<vector<vector<int>>>& dp)
{
    int n = prices.size();
    // base case
    if(i >=n || limit == 0) return 0;

    if(dp[i][buy][limit] != -1)
    {
        return dp[i][buy][limit];
    }

    int profit = 0;
    if(buy) 
    {
        int buyProfit = -prices[i] + maxProfit_TopDown(prices,i+1,0,limit,dp);
        int skipBuy = maxProfit_TopDown(prices,i+1,1,limit,dp);
        profit = max(buyProfit, skipBuy);
    }
    else 
    {
        int sellProfit = prices[i] + maxProfit_TopDown(prices,i+1,1,limit-1,dp);
        int skipSell = maxProfit_TopDown(prices,i+1,0,limit,dp);
        profit = max(sellProfit, skipSell);
    }

    dp[i][buy][limit] = profit;
    return dp[i][buy][limit];
}

// Using Tabulation - Bottom Up
int maxProfit_BottomUp(vector<int>& prices)
{
    vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));

    for(int i = prices.size()-1; i >= 0; i--)
    {
        for(int buy = 0; buy < 2; buy++)
        {
            for(int limit = 1; limit < 3; limit++)
            {
                int profit = 0;
                if(buy) 
                {
                    int buyProfit = -prices[i] + dp[i+1][0][limit];
                    int skipBuy = dp[i+1][1][limit];
                    profit = max(buyProfit, skipBuy);
                }
                else 
                {
                    int sellProfit = prices[i] + dp[i+1][1][limit-1];
                    int skipSell = dp[i+1][0][limit];
                    profit = max(sellProfit, skipSell);
                }

                dp[i][buy][limit] = profit;
            }
        }
    }

    return dp[0][1][2];
}

// Using Space Optimisation
int maxProfit_SpaceOpti(vector<int>& prices)
{
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(3, 0)));

    for(int i = prices.size()-1; i >= 0; i--)
    {
        for(int buy = 0; buy < 2; buy++)
        {
            for(int limit = 1; limit < 3; limit++)
            {
                int profit = 0;
                if(buy) 
                {
                    int buyProfit = -prices[i] + dp[1][0][limit];
                    int skipBuy = dp[1][1][limit];
                    profit = max(buyProfit, skipBuy);
                }
                else 
                {
                    int sellProfit = prices[i] + dp[1][1][limit-1];
                    int skipSell = dp[1][0][limit];
                    profit = max(sellProfit, skipSell);
                }

                dp[0][buy][limit] = profit;
            }
        }
        dp[1] = dp[0];
    }

    return dp[0][1][2];
}

int main()
{
    vector<int> prices{3,3,5,0,0,3,1,4};

    // here 0 is index and 1 is can buy (true) and 2 is limit atmost 2 times can buy or sell
    // int ans = maxProfit_RE(prices,0,1,2);

    // vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
    // int ans = maxProfit_TopDown(prices,0,1,2,dp);

    // int ans = maxProfit_BottomUp(prices);
    int ans = maxProfit_SpaceOpti(prices);

    cout << "Max Profit is:: " << ans << endl;

    return 0;
}