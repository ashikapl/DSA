#include <iostream>
#include <string>
using namespace std;

string integerToRoman(int x)
{
    int arr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int n = 13;
    string ch[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string ans = "";

    for (int i = 0; i < n; i++)
    {
        while (x >= arr[i])
        // x = 290
        {
            ans += ch[i];
            x = x - arr[i];
        }
    }
    return ans;
}

int main()
{
    int x = 290;

    string ans = integerToRoman(x);

    cout << ans << endl;

    return 0;
}