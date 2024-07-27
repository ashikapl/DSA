// Longest Common Subsequence (leetCode-1143) Using recursion, memoisation, tabulation
// TC -> O(2^n) to O(n*m) from recursion to tabulation
// SC -> O(n*m) to O(n*m) from recursion to tabulation
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Recursion 
int LCSUsingRecursion(string a, string b, int i, int j)
{
    // base case
    int n = a.length();
    int m = b.length();
    if(i == n) return 0;
    if(j == m) return 0;

    int ans = 0;
    if(a[i] == b[j]) // here this two index value is match so in length we have to add 1
    {
        ans = 1 + LCSUsingRecursion(a,b,i+1,j+1); // increment both i and j
    }
    else
    {
        // if values are not match then include & exclude pattern and find max from both callss
        // if we ignore (a-string) ith value then increment i by 1
        // or if we ignore (b-string) ith value then increment j by 1
        // return maximum length by comparing both subsequennce length
        ans = 0 + max(LCSUsingRecursion(a,b,i+1,j),LCSUsingRecursion(a,b,i,j+1));
    }
    
    return ans;
}

// Memoisation Approach  a,b string pass by reference becoz for no memory leak and no TLE
int LCSUsingMemo(string& a, string& b, int i, int j, vector<vector<int> >&dp)
{
    // base case
    int n = a.length();
    int m = b.length();
    if(i == n) return 0;
    if(j == m) return 0;

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;
    if(a[i] == b[j])
    {
        ans = 1 + LCSUsingMemo(a,b,i+1,j+1,dp); 
    }
    else
    {
        ans = 0 + max(LCSUsingMemo(a,b,i+1,j,dp),LCSUsingMemo(a,b,i,j+1,dp));
    }
    
    dp[i][j] = ans;
    return ans;

}

// Tabulation Approach 
int LCSUsingTab(string& a, string& b)
{
    vector<vector<int>> dp(a.length()+1, vector<int>(b.length()+1, 0));

    for(int i = a.length()-1; i >= 0; i--)
    {
        for(int j = b.length()-1; j >= 0; j--)
        {
            int ans = 0;
            if(a[i] == b[j])
            {
                ans = 1 + dp[i+1][j+1]; 
            }
            else
            {
                ans = 0 + max(dp[i+1][j],dp[i][j+1]);
            }
            
            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

int LCSUsingSpaceOpti(string& a, string& b)
{
    vector<int> curr(a.length()+1, 0);
    vector<int> next(b.length()+1, 0);
     
    for(int i = a.length()-1; i >= 0; i--)
    {
        for(int j = b.length()-1; j >= 0; j--)
        {
            int ans = 0;
            if(a[i] == b[j])
            {
                ans = 1 + next[j+1]; 
            }
            else
            {
                ans = 0 + max(next[j],curr[j+1]);
            }
            
            curr[j] = ans;
        }
        next = curr;
    } 
    return next[0];
}

int main()
{
    string a = "abcde";
    string b = "ace";

    // int i = 0;
    // int j = 0;

    // int ans = LCSUsingRecursion(a,b,i,j);

    // vector<vector<int> >dp(a.length(), vector<int>(b.length(), -1));
    // int ans = LCSUsingMemo(a,b,i,j,dp);

    // int ans = LCSUsingTab(a,b);

    int ans = LCSUsingSpaceOpti(a,b);

    cout << "Longest Common Subsequence length:- " << ans << endl;

    return 0;
}