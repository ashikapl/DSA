#include <iostream>
using namespace std;

int main()
{
    int arr[4][2] = {{10, 11}, {2, 3}, {3, 3}};
    int a, b;

    cout << "Printing 2d array " << endl;

    for (a = 0; a < 4; a++)
    {
        for (b = 0; b < 2; b++)
        {
            cout << arr[a][b] << " ";
        }
        cout << endl;
    }

    return 0;
}