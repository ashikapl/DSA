// Find the duplicate element //
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr{1, 2, 3, 2, 4, 5};

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            cout << arr[i];
        }
    }

    // Positioning method //
    // while (arr[0] != arr[arr[0]])
    // {
    //     swap(arr[0], arr[arr[0]]);
    // }

    // cout << arr[0];

    return 0;
}