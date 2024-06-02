// Sum of Even NO. upto N //

#include <iostream>
using namespace std;

// Declaring the function
int getSum(int n)
{
    int sum = 0;
    for (int i = 2; i <= n; i = i + 2)
    {
        sum = sum + i;
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter the value: ";
    cin >> n;

    // Calling the function
    int ans = getSum(n);

    cout << "The sum is: " << ans;

    return 0;
}