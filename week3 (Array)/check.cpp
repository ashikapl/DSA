#include <iostream>
using namespace std;

int *set(int arr[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] == k)
            {
                i++;
            }
            else
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
    return arr;
}

int main()
{
    int arr[] = {12, 11, 15, 14, 10};
    int n = 5;
    int k = 3;

    set(arr, n, k);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}