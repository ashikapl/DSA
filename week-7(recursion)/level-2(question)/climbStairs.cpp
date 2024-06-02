// climbing Stairs with recursion but time complexity is not good
#include <iostream>
using namespace std;

int climbStairs(int n)
{
    // base case
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    // Recursive relation
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
    int n;
    cout << "Enter the nth stair:- ";
    cin >> n;

    int ans = climbStairs(n);

    cout << "The number of way to climb " << n << " "
         << "stairs:- " << ans << endl;

    return 0;
}