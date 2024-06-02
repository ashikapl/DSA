// Fancy Pattern #1 //

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        // Stars //
        for (int j = 0; j <= (n * 2) - i - 2; j++)
        {
            cout << "*";
        }

        // Numbers with stars //
        for (int j = 2; j <= i + 1; j++)
        {
            if (j == i + 1)
            {
                cout << i;
            }
            else
            {
                cout << i << "*";
            }
        }

        // Stars //
        for (int j = 0; j <= (n * 2) - i - 2; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}