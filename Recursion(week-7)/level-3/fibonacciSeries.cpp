// fibonacci series
#include <iostream>
using namespace std;

int fib(int n)
{
    // base case
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    // R.R
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;

    int ans = fib(n);

    cout << ans << endl;

    return 0;
}