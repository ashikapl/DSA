// Fancy pattern #2 //

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < r + 1; c++)
        {
            cout << r + 1;
            if (c != r)
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n - r; c++)
        {
            cout << n - r;
            if (c != n - r - 1)
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}