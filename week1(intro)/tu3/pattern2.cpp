#include <iostream>
using namespace std;

int main()
{

    // Hollow rectangle pattern //

    int rowCount;
    int colCount;
    cin >> rowCount >> colCount;

    for (int r = 0; r < rowCount; r = r + 1)
    {
        if (r == 0 || r == rowCount)
        {
            for (int c = 0; c < rowCount-1; c = c + 1)
            {
                cout << "*"
                     << " ";
            }
        }
        else
        {
            cout << "*"
                 << " ";
            for (int c = 0; c < colCount-2; c = c + 1)
            {
                cout << " ";
            }
            cout << "*"
                 << " ";
        }
        cout << endl;
    }
}