// Wild card matching using recursion
#include <iostream>
#include <string>
using namespace std;

bool checkMatch(string &s, int si, string &p, int pi)
{
    // base case
    if (si == s.size() && pi == p.size())
    {
        return true;
    }
    if (si == s.size() && pi < p.size())
    {
        while (pi < p.size())
        {
            if (p[pi] != '*')
            {
                return false;
            }
            pi++;
        }
        return true;
    }

    // single char matching
    if (s[si] == p[pi] || '?' == p[pi])
    {
        return checkMatch(s, si + 1, p, pi + 1);
    }
    if (p[pi] == '*')
    {
        // treat * is empty
        bool caseA = checkMatch(s, si, p, pi + 1);

        // let * comsume one char
        bool caseB = checkMatch(s, si + 1, p, pi);
    }

    // no char matches
    return false;
}

int main()
{
    string s = "abcd";
    string p = "abcd";

    int si = 0; // pointer to s string
    int pi = 0; // pointer to p string

    bool isMatch = checkMatch(s, si, p, pi);

    if (isMatch)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}