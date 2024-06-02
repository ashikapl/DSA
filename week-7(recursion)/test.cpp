#include <iostream>
using namespace std;

void set(int arr[], int n)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (arr[i] < 0 || arr[j] > 0)
        {
            swap(arr[j], arr[i]);
            i++;
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 3, -2, 5, -1};
    int n = 5;

    set(arr, n);

    return 0;
}