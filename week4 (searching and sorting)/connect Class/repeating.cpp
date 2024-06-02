// C++ program to Find the two repeating
// elements in a given array
#include <bits/stdc++.h>
using namespace std;

void printRepeating(int arr[], int size)
{
    sort(arr, arr + size);
    cout << "Repeating elements are ";
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            cout << arr[i] << " ";
        }
    }
}

// Driver code
int main()
{
    int arr[] = {4, 2, 4, 5, 2, 3, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printRepeating(arr, arr_size);
    return 0;
}
