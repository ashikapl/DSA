#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int a = 4;
    int b = 8;

    int ans = gcd(a, b);

    cout << ans << endl;

    return 0;
}