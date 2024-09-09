#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;

        start++;
        end--;
    }
    return true;
}

string longestPalindrome(string s, int n)
{
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, i, j))
            {
                string t = s.substr(i, j - i + 1); // i is start and j is length
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }
    return ans;
}

int main()
{
    string s = "babad";
    int n = s.length();

    string ans = longestPalindrome(s,n);
    cout << ans << endl;

    return 0;
}