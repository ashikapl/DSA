// Check palindrome (RE)
#include <iostream>
#include <string>
using namespace std;

bool checkPalin(string &s, int start, int end)
{
    // base case
    if (start >= end)
    {
        return true;
    }

    // Solve one case
    if (s[start] != s[end])
    {
        return false;
    }

    // baaki recursion smbhal lega
    return checkPalin(s, start + 1, end - 1);
}

int main()
{
    string s;
    cin >> s;

    bool ans = checkPalin(s, 0, s.size() - 1);

    if (ans == true)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}