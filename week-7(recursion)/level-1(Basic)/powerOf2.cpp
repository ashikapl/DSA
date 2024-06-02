// find the power of 2^n
#include <iostream>
using namespace std;

int findPower(int n)
{
    // base case
    if (n == 1)
        return 2;

    // recursive relation
    int ans = 2 * findPower(n - 1);

    return ans;
}

int main()
{
    int n;
    cout << "Enter the power:- ";
    cin >> n;

    cout << findPower(n);

    return 0;
}