#include <iostream>
using namespace std;

int func(int a, int b)
{
    if (b == 0)
        return 0;
    if (b == 1)
        return a;

    return a + func(a, b - 1);
}

int main()
{
    int ans = func(3, 8);

    cout << ans;

    return 0;
}