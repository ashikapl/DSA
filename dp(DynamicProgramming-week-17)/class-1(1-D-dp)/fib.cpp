// fibonacci with Top-Down , Bottom-Up approach  and Space Optimization
// 1-D dp -> only 1 parameter is change or 1-dimentional array

// fibonacci series -> 0,1,1,2,3,5,8,13,21,34,55..........

#include<iostream>
#include<vector>
using namespace std;

// Recursive Approach ->TC->[O(2^n)] && SC->[O(n)]
int fib(int n)
{
    // base case
    if(n == 1 || n == 0)
    {
        return n;
    }

    int ans = fib(n-1) + fib(n-2);
    return ans;
}

// TopDown -> recursion + memoisation  approch (n->0)
// TC -> [O(n)] && SC -> [O(n) + O(n)]
int memoApproach(int n, vector<int> &dp)
{
    // base case
    if(n == 1 || n == 0)
    {
        return n;
    }

    // step3: check if ans is already exist
    if(dp[n] != -1)
    {
        return dp[n];
    }

    // step2: store the value in dp
    dp[n] = memoApproach(n-1,dp) + memoApproach(n-2,dp);
    return dp[n];
}

// Bottom-Up -> Tabulation or iterative Approach (0->n)
// TC -> [O(n)] && SC -> [O(n)]
int tabularApproach(int n)
{
    // step1 : create the dp array
    vector<int> dp(n+1,-1);

    // step2: observe base case and initailize it
    dp[0] = 0;
    if(n == 0) return dp[n];
    
    dp[1] = 1; 
    if(n == 1) return dp[n];

    // step3: iterate the array in 0->n approach
    for(int i = 2; i <= n; i++) // here we start from 2 becoz 0 and 1 is initailize before it
    {
        dp[i] = dp[i-1] + dp[i-2]; // apply same formula as top-Down approach
    }

    return dp[n];
}

// Space Optimization Approach with constant space
// TC->[O(n)] && SC->[O(1)] 
// In this approach we have to observe the pattern then optimize it
int spaceOptimal(int n)
{
    int prev2 = 0;
    int prev1 = 1;
    int curr;

    for(int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        // shifting the values
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main()
{
    int n;
    cout << "Enter the value of nth fib:-> ";
    cin >> n;
    
    // int ans = fib(n) -> (recursive approach)
    // cout << "Nth fib no is:-> " << ans << endl;

    // top-Down -> (recursion + memoisation approach)
    // step1: create a dp array
    vector<int> dp(n+1,-1);
    int ans = memoApproach(n,dp);
    cout << "Nth fib no is:-> " << ans << endl;

    // Tabulation or Iterative Approach
    // int ans = tabularApproach(n);
    // cout << "Nth fib no is:-> " << ans << endl;

    // Space Optimization method
    // int ans = spaceOptimal(n);
    // cout << "Nth fib no is:-> " << ans << endl;

    return 0;
}