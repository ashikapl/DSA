#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        int start = 1;
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 || i == 5)
            {
                if (i % 2 == 0)
                {
                    cout << start;
                    start = start + 1;
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}