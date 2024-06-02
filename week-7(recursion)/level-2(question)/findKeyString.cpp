// Find a key in string array
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findKey(string &s, int &n, int i, char &key, vector<int> &ans)
{
    // base case
    if (i >= n)
        return -1;

    // 1 case mein solve karlu
    if (s[i] == key)
        ans.push_back(i);

    // R.R
    return findKey(s, n, i + 1, key, ans);
}

int main()
{
    string s = "lovebabbar";
    int n = s.length();

    char key = 'b';
    int i = 0;

    vector<int> ans; // to store indexies and print all index where the value is store

    findKey(s, n, i, key, ans);

    cout << "Answer at index:- ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}