#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printStringSquences(string &s, string output, int i, vector<string> &ans)
{
    // base case
    if (i >= s.length())
    {
        // cout << output << endl;
        ans.push_back(output);
        return;
    }

    // exclude
    printStringSquences(s, output, i + 1, ans);

    // include
    printStringSquences(s, output + s[i], i + 1, ans); // output + s[i] mein s[i] push_back kiya hai output main
}

int main()
{
    string s = "abc";
    string output = "";

    int i = 0;
    vector<string> ans;

    printStringSquences(s, output, i, ans);

    cout << "printing the sequences:- " << endl;
    for (auto val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Size of ans " << ans.size();

    return 0;
}