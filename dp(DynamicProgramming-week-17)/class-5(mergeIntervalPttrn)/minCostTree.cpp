// Minimum Cost Tree from leaf values (leetcode - 1130) medium
// solve Using recursion, memoisation, tabulation, but not space optimize Approach
// TC -> O(2^n) to O(n3) from recursion to tabulation
// SC -> O(n2) to O(n2) from recursion to tabulation
#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Using Recursion
int minCostTreeUsingRecursion(vector<int>& arr, map<pair<int,int>, int> &maxi, int left, int right)
{
    // base case
    if(left == right) return 0;

    int ans = INT_MAX; // we have to find min cost 
    for(int i = left; i < right; i++)
    {
        ans = min(ans, maxi[{left,i}]*maxi[{i+1,right}]
                       + minCostTreeUsingRecursion(arr,maxi,left,i)
                       + minCostTreeUsingRecursion(arr,maxi,i+1,right));
    }
    return ans;
}

// Using Memoisation
int minCostTreeUsingMemo(vector<int>& arr, map<pair<int,int>, int> &maxi, int left, int right, vector<vector<int> >&dp)
{
    // base case
    if(left == right) return 0;

    if(dp[left][right] != -1)
    {
        return dp[left][right];
    }

    int ans = INT_MAX; // we have to find min cost 
    for(int i = left; i < right; i++)
    {
        ans = min(ans, maxi[{left,i}]*maxi[{i+1,right}]
                       + minCostTreeUsingMemo(arr,maxi,left,i,dp)
                       + minCostTreeUsingMemo(arr,maxi,i+1,right,dp));
    }
    dp[left][right] = ans;
    return dp[left][right];
}

// Using Tabulation
int minCostTreeUsingTab(vector<int>& arr, map<pair<int,int>, int>& maxi, int left, int right)
{
    int n = arr.size()-1;
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    
    for(int left = n; left >= 0; left--)
    {
        for(int right = 0; right <= n; right++)
        {
            if(left >= right) 
            { 
                continue;
            }
            else
            {
                int ans = INT_MAX; // we have to find min cost 
                for(int i = left; i < right; i++)
                {
                    ans = min(ans, maxi[{left,i}]*maxi[{i+1,right}]+ dp[left][i] + dp[i+1][right]);
                }
                dp[left][right] = ans;
            }
        }
    }
    return dp[0][n];
}

int main()
{
    vector<int> arr{6,2,4};
    int n = arr.size()-1;

    map<pair<int,int>, int> maxi;

    for(int i = 0; i <= n; i++)
    {
        maxi[{i,i}] = arr[i];
        for(int j = i+1; j <= n; j++)
        {
            maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
        }
    }
    
    // int n = arr.size();
    // int ans = minCostTreeUsingRecursion(arr,maxi,0,n);

    // vector<vector<int> >dp(n+1, vector<int>(n+1, -1));
    // int ans = minCostTreeUsingMemo(arr,maxi,0,n,dp);

    int ans = minCostTreeUsingTab(arr,maxi,0,n);

    cout << "Minimum cost tree from leaf value:: " << ans << endl;

    return 0;

}