// find the index of first occurence (leetcode - 28)

#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();

    for (int i = 0; i < n - m; i++) // n-m means larger than n size out of bound
    {
        for (int j = 0; j < m; j++)
        {
            if (needle[j] != haystack[i + j])
            {
                break;
            }
            if (j == m - 1)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    string haystack = "leetsadcodesad";
    string needle = "sad";

    int ans = strStr(haystack, needle);

    cout << "Index of first occurence of needle is:-> " << ans;

    return 0;
}