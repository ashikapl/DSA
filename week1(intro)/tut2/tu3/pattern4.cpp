// Inverted Half Pyramid //

#include <iostream>

using namespace std;

int main()
{

    int num;
    cin >> num;

    for (int row = 0; row < num; row = row + 1)
    {
        for (int col = 0; col < num - row; col = col + 1)
        {
            cout << "*"
                 << " ";
        }

        cout << endl;
    }
}