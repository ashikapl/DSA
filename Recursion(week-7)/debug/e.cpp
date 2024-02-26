#include <iostream>
using namespace std;

int multiplyNumbers(int m, int n)
{
    if (n <= 0)
        return 0;
    return m + multiplyNumbers(m, n - 1);
}

int main()
{
    int m = 1;
    int n = 3;

    int ans = multiplyNumbers(m, n);

    cout << ans;

    return 0;
}