#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end);
void merge_sort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void merge(int arr[], int start, int mid, int end)
{
    int left[mid - start + 1];
    int right[end - mid];
    for (int i = 0; i <= mid - start; i++)
    {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < end - mid; j++)
    {
        right[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = start;
    while (i <= mid - start && j < end - mid)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i <= mid - start)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < end - mid)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

int main()
{
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}