// find the answers //

#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 10;

    // Pre and post increment , decrement //
    int ans1 = (++a) * (--b);
    int ans2 = (++a) * (b--);
    int ans3 = (a++) * (--b);
    int ans4 = (a++) * (b--);

    cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4;
}