// Partition Equal Subset Sum Using Recursion, memoization, tabulation, and space optimization
// TC -> O(2^n) to O(n*m*k) from recursion to space optimization 
// SC -> O(2^n) to O(n) from recursion to space optimization
// 2D - dp

#include<iostream>
#include<vector>
using namespace std;

// using simple recursion
bool paritionSumUsingRecursion(int nums[], int n , int index, int target)
{
    // base case
    if(index >= n) return 0;
    if(target < 0) return 0;
    if(target == 0) return 1;

    bool include = paritionSumUsingRecursion(nums, n, index+1, target - nums[index]);
    bool exclude = paritionSumUsingRecursion(nums, n, index+1, target);

    return (include || exclude);
}

// Memoisation Approach 
bool paritionSumUsingMemo(int nums[], int n , int index, int target, vector<vector<int> >& dp)
{
    // base case
    if(index >= n) return 0;
    if(target < 0) return 0;
    if(target == 0) return 1;

    if(dp[index][target] != -1)
    {
        return dp[index][target];
    }

    bool include = paritionSumUsingMemo(nums, n, index+1, target - nums[index], dp);
    bool exclude = paritionSumUsingMemo(nums, n, index+1, target, dp);

    dp[index][target] = (include || exclude);
    return dp[index][target];
}

bool partitionSumUsingTab(int nums[], int n, int target)
{
    vector<vector<int> > dp(n+1, vector<int>(target+1, 0));
    for(int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    for(int index = n-1; index >= 0; index--)
    {
        for(int t = 1; t <= target; t++)
        {
            bool include = 0;
            if(t - nums[index] >= 0)
            {
                include = dp[index+1][t - nums[index]];
            }
            bool exclude = dp[index+1][t];

            dp[index][t] = (include || exclude);
        }
    }
    return dp[0][target];
}

bool partitionSumUsingSpaceOpti(int nums[], int n, int target)
{
    vector<int> curr(target+1, 0);
    vector<int> next(target+1, 0);

    curr[0] = 1;
    next[0] = 1;

    for(int index = n-1; index >= 0; index--)
    {
        for(int t = 1; t <= target; t++)
        {
            bool include = 0;
            if(t - nums[index] >= 0)
            {
                include = next[t - nums[index]];
            }
            bool exclude = next[t];

            curr[t] = (include || exclude);
        }
        next = curr;
    }
    return next[target];
}

bool partitionSumUsingSpaceOpti2(int nums[], int n, int target)
{
    vector<int> curr(target+1, 0);
    // vector<int> next(target+1, 0);

    curr[0] = 1;
    // next[0] = 1;

    for(int index = n-1; index >= 0; index--)
    {
        for(int t = 1; t <= target; t++)
        {
            bool include = 0;
            if(t - nums[index] >= 0)
            {
                include = curr[t - nums[index]];
            }
            bool exclude = curr[t];

            curr[t] = (include || exclude);
        }
        // next = curr;
    }
    return curr[target];
}

int main()
{
    int nums[4]= {1,5,11,5};
    int n = 4;

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    int target = sum/2;
    if(sum & 1)
    {
        cout << "Odd sum can't divide!" << endl;
    }

    // int index = 0;

    // simple recursion
    // bool ans = paritionSumUsingRecursion(nums,n,index,target);

    // memoization approach 
    // vector<vector<int> >dp(n, vector<int>(target+1, -1));
    // bool ans = paritionSumUsingMemo(nums,n,index,target,dp);

    // Tabulation approach
    // bool ans = partitionSumUsingTab(nums,n,target);

    // Space Optimization
    // bool ans = partitionSumUsingSpaceOpti(nums,n,target);

    bool ans = partitionSumUsingSpaceOpti2(nums,n,target);

    if(ans)
    {
        cout << "The array can be divide into two equal sum value:- " << "True" << endl; 
    }
    else
    {
        cout << "Can't divide into equal parts!" << endl;
    }

    return 0;
}