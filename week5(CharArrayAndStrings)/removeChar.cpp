#include <iostream>
#include <string>
using namespace std;

string removeChar(string S)
{
    string ans;
    for (int i = 0; i < S.length(); i++)
    {
        if (!isalpha(S[i]))
            ans.push_back(S[i]);
    }
    return ans;
}

int main()
{
    string S = "AA1d23cBB4";

    cout << removeChar(S);

    return 0;
}