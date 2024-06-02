// check prime //

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << "  Its not a prime no." << endl;
        }

        cout << "  Its a prime no." << endl;
    }

    int a = 5;
    char b = 'd';
    int sum = a + b;
    cout << sum << endl;

    float f = 2.1 + sum;
    cout << f;
}