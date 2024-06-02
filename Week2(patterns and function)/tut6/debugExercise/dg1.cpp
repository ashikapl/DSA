#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int64_t sum = 0; // Use int64_t for larger range
    for (int i = 1; i <= n; ++i)
    {
        sum += i;
    }
    cout << sum << endl;
    return 0;
}
