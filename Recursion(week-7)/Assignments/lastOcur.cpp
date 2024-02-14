// Find the last occurence of char // TC & SC -> O(n)
#include <iostream>
#include <string>
using namespace std;

void lastOccuLTR(string &s, char x, int i, int &ans)
{
    // base case
    if (i >= s.size())
    {
        return;
    }

    // solve 1 case
    if (s[i] == x)
    {
        ans = i;
    }

    lastOccuLTR(s, x, i + 1, ans);
}

void lastOccuRTL(string &s, char x, int i, int &ans)
{
    // base case
    if (i < 0)
    {
        return;
    }

    // solve 1 case
    if (s[i] == x)
    {
        ans = i;
        return;
    }

    lastOccuRTL(s, x, i - 1, ans);
}

int main()
{
    string s;
    cin >> s;

    char x;
    cin >> x;

    int ans = -1;

    // lastOccuLTR(s, x, 0, ans); // Left to right and here 0 is index

    lastOccuRTL(s, x, s.size() - 1, ans); // right to left search from last index

    cout
        << ans << endl;

    return 0;
}