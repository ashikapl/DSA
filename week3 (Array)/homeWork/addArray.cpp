// sum the digits which is stored in an array
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string calculateSum(int a[], int b[], int sizea, int sizeb)
{
    string ans;
    int carry = 0;
    int i = sizea - 1;
    int j = sizeb - 1;

    while (i >= 0 && j >= 0)
    {
        int x = a[i] + b[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        i--;
        j--;
    }

    // if b arar iteration is over
    while (i >= 0)
    {
        int x = a[i] + 0 + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        i--;
        j--;
    }

    // if a iteration is over
    while (j >= 0)
    {
        int x = 0 + b[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        i--;
        j--;
    }

    if (carry)
    {
        ans.push_back(carry + '0');
    }

    while (ans[ans.size() - 1] == 0)
    {
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int a[] = {2, 3, 5, 2};
    int b[] = {3, 2, 6};
    int sizea = 4;
    int sizeb = 3;

    string ans = calculateSum(a, b, sizea, sizeb);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}