#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string &str)
{
    int i = 0;
    int j = str.size() - 1;

    while (i <= j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    string str = "ababa";

    bool ans = checkPalindrome(str);

    if (ans == true)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}