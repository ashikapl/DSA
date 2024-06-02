// Floyd's pattern //

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int start = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << start << " ";
            start++;
        }
        cout << endl;
    }
}