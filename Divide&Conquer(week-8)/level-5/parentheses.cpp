// Generate Parentheses
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(vector<string> &ans, int n, int open, int close, string output)
{
    // base case
    if (open == 0 && close == 0)
    {
        ans.push_back(output);
        return;
    }

    // include open bracket
    if (open > 0)
    {
        output.push_back('(');
        // recursion
        solve(ans, n, open - 1, close, output);
        // backtrack
        output.pop_back();
    }

    // include close bracket
    if (close > open)
    {
        output.push_back(')');
        // recursion
        solve(ans, n, open, close - 1, output);
        // backTrack
        output.pop_back();
    }
}

int main()
{
    int n;
    cout << "Enter the value:-> ";
    cin >> n;

    vector<string> ans;

    int open = n;
    int close = n;

    string output = "";

    solve(ans, n, open, close, output);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}