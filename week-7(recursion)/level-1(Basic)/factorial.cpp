// find factorial using recursion
#include <iostream>
using namespace std;

int fact(int n)
{
    // B.C
    if (n == 1)
        return 1;

    // R.R
    int ans = n * fact(n - 1);

    return ans;
}

int main()
{
    int n;
    cout << "Enter the value which want to find the factorial of:- ";
    cin >> n;

    cout << "The factorial of " << n << " "
         << "is"
         << " " << fact(n);

    return 0;
}