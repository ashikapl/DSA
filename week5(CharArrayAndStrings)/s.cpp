#include <iostream>
#include <string>
using namespace std;

string remove(string s)
{
    string ans;

    for (int i = 0; i < s.length(); i++)
    {
        if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' ||
              s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'))
        {
            ans.push_back(s[i]);
        }
    }
    return ans;
}

int main()
{
    string s = "Welcome to geeksofgeeks";

    cout << remove(s);

    return 0;
}