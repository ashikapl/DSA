// Edit Distance of both string
// find the minimum no of operations to make two string equal
#include<iostream>
#include<string>
using namespace std;

int solve(string s1, string s2, int i, int j)
{
    int ans = 0;
    if(i == s1.length()) return 0;
    if(j == s2.length()) return 0;

    if(s1[i] == s2[j])
    {
        ans = solve(s1, s2, i+1, j+1);
    }
    else
    {
        int insert = 1 + solve(s1, s2, i+1, j);
        int deleted = 1 + solve(s1, s2, i, j+1);
        int replace = 1 + solve(s1, s2, i+1, j+1);

        ans = min(insert, min(deleted,replace));
    }

    return ans;
}

int main()
{
    string s1 = "geek";
    string s2 = "gesek";

    int ans = solve(s1,s2,0,0);
    cout << "Min operation to make two string equal:- " << ans;

    return 0;
}