// Numeric Half Pyramid //

#include <iostream>

using namespace std;

int main ()
{
    for (int r = 0; r < 6; r = r + 1)
    {
        for (int c = 0; c < r + 1; c = c + 1)
        {
            cout << c + 1 << " " ;
        }

        cout << endl ;
    }
}