// Coin Change by recursion, memoisation and tabular approach
#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecursion(vector<int>& coins, int amount)
{
    if(amount == 0)
    {
        return 0;
    }
    if(amount < 0)
    {
       return INT_MAX;
    }

    int mini = INT_MAX;
    for(int i = 0; i < coins.size(); i++)
    {
        int ans = solveUsingRecursion(coins, amount - coins[i]);
        if(ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}

int solveUsingMemo(vector<int>& coins, int amount, vector<int> &dp)
{
    if(amount == 0)
    {
        return 0;
    }
    if(amount < 0)
    {
        return INT_MAX;
    }
    if(dp[amount] != -1)
    {
        return dp[amount];
    }

    int mini = INT_MAX;
    for(int i = 0; i < coins.size(); i++)
    {
        int ans = solveUsingMemo(coins, amount - coins[i], dp);
        if(ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }    
    dp[amount] = mini;
    return dp[amount];
}

int solveUsingTabulation(vector<int>& coins, int amount)
{
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;

    for(int target = 1; target <= amount; target++)
    {
        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++)
        {
            if(target - coins[i] >= 0)
            {
                int ans = dp[target - coins[i]];
                if(ans != INT_MAX)
                {
                    mini = min(mini, 1 + ans);
                }
            }
        }
        dp[target] = mini;
    }
    return dp[amount];
}

int main()
{
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    int amount = 11;

    // int ans = solveUsingRecursion(coins,amount);
    // if(ans == INT_MAX)
    //     return -1;
    // else
    //     return ans;

    // memoisation
    // vector<int> dp(amount+1,-1);
    // int ans = solveUsingMemo(coins,amount,dp);
    // if(ans == INT_MAX)
    //     return -1;
    // else
    //     return ans;

    int ans = solveUsingTabulation(coins,amount);
    if(ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << "Minimum no of coins are: " << ans << endl;

    return 0;
}