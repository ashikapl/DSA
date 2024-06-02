// Find the missing number with duplicate//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findMissing(int arr[], int size)
{
    // visited method
    // for (int i = 0; i < size; i++)
    // {
    //     int index = abs(arr[i]);

    //     if (arr[index - 1] > 0)
    //     {
    //         arr[index - 1] *= -1;
    //     }
    // }

    // // print missing number
    // for (int i = 0; i < size; i++)
    // {
    //     if (arr[i] > 0)
    //         cout << i + 1 << " ";
    // }

    // sorting + swapping method
    int i = 0;
    while (i < size)
    {
        int index = arr[i] - 1;
        if (arr[i] != arr[index])
        {
            swap(arr[i], arr[index]);
        }
        else
        {
            ++i;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != i + 1)
        {
            cout << i + 1 << " ";
        }
    }
}

int main()
{
    int arr[] = {3, 5, 2, 1, 5};
    int size = 5;

    findMissing(arr, size);

    return 0;
}