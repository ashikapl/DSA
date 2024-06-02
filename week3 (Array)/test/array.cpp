//

#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int size = 10;
    int start = 0;

    // find maximum value
    // int max = INT_MIN;

    // for (int i = 0; i < size; i++)
    // {
    //     if (arr[i] > max)
    //     {
    //         max = arr[i];
    //     }
    // }

    // cout << "The maximum no. is:- " << max;

    // find sum
    for (int i = 0; i < size; i++)
    {
        start = arr[i] + start;
    }

    cout << start;

    return 0;
}