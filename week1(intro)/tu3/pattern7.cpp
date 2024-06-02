// Full Pyramid //

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int r = 0; r < n; r = r + 1)
    {
        int k = 0;
        for (int c = 0; c < ((2 * n) - 1); c = c + 1)
        {
            if (c < n - r - 1)
            {
                cout << " ";
            }
            else if (k < 2 * r + 1)
            {
                cout << "*";
                k++;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}