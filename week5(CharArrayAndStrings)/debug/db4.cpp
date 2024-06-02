#include <iostream>
#include <string>
using namespace std;

string isPalindrome(string S)
{
    int N = S.length();
    for (int i = 0; i < (N / 2); i++)
    {
        if (S[i] != S[N - i - 1])
        {
            return "No";
        }
    }
    return "Yes";
}

int main()
{
    string S = "naen";

    cout << isPalindrome(S);

    return 0;
}