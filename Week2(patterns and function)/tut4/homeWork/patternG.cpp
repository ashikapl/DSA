// Numeric Palindrone Equilateral Pyramid //

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        // Spaces //
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // half numeric pyramid //
        for (int j = 1; j < i + 1; j++)
        {
            cout << j;
        }

        // reverse counting //
        for (int j = i - 1; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}