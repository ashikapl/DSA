#include <iostream>
using namespace std;

void solve(int *p)
{
    *p = (*p) * (-1);
}

int main()
{
    int a = 10;
    solve(&a);
    cout << a;

    return 0;
}