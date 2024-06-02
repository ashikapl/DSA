// print substring
#include <iostream>
#include <string>
using namespace std;

int expandIndex(string str, int i, int j)
{
    int count = 0;
    while (str[i] == str[j] && i >= 0 && j < str.length())
    {
        count++;
        i--;
        j++;
    }

    return count;
}

int countSubstring(string str)
{
    int totalcount = 0;
    int n = str.length();

    for (int i = 0; i < n; i++)
    {
        // odd
        int oddAns = expandIndex(str, i, i);
        totalcount = totalcount + oddAns;

        // even
        int evenAns = expandIndex(str, i, i + 1);
        totalcount = totalcount + evenAns;
    }

    // print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << str[i] << " " << str[j];
        }
        cout << endl;
    }

    return totalcount;
}

int main()
{
    string str = "abc";

    int ans = countSubstring(str);

    cout << ans;

    return 0;
}