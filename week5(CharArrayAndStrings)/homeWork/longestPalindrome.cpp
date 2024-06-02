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

string longestPalindrome(string s)
{
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; i < s.size(); j++)
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

    longestPalindrome(s);

    return 0;
}