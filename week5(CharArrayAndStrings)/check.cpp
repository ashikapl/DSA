#include <iostream>
#include <string>
using namespace std;

bool check(string S)
{
    char first = S[0];

    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] != first)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string S = "sss";

    if (check(S) == true)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}