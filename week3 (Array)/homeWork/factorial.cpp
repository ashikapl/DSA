// Find the factorial of a number
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findFactorial(int n)
{
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int x = ans[j] * i + carry;
            ans[j] = x % 10;
            carry = x / 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }

    reverse(ans.begin(), ans.end());

    for (int e : ans)
    {
        cout << e;
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number:- ";
    cin >> n;

    findFactorial(n);
}