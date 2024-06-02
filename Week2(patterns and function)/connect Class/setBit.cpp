// count the no of bit of decimal no. //

#include <iostream>
using namespace std;

int main()
{
    int n = 15;

    // ans --> store no. of set bit
    int ans = 0;

    while (n != 0)
    {
        // Found one set bit
        // so increment set bit count
        if (n & 1)
        {
            ans++;
        }

        // Shift in right side
        n = n >> 1;
    }

    cout << "Number of set bit are: " << ans;
}
