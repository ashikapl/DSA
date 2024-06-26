#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

bool isPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
        }
        else
        {
            // s[i] == s[j]
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    string s = "race a car";

    isPalindrome(s);

    if (isPalindrome(s) == true)
    {
        cout << "True";
    }
    else
    {
        cout << "false";
    }
}