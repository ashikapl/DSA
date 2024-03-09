// Count Inverse problem using merge sort (algo)
#include <iostream>
#include <vector>
using namespace std;

long merge(vector<int> &arr, vector<int> &temp, int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start;
    long c = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            c += mid - i - 1;
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    while (start <= end)
    {
        arr[start] = temp[start];
        ++start;
    }

    return c;
}

long mergeSort(vector<int> &arr, vector<int> &temp, int start, int end)
{
    if (start >= end)
        return 0;
    int mid = start + (end - start) / 2;
    long c = 0;

    c += mergeSort(arr, temp, start, mid);
    c += mergeSort(arr, temp, mid + 1, end);
    c += merge(arr, temp, start, mid, end);

    return c;
}

long countInverse(vector<int> &arr)
{
    long c = 0;
    vector<int> temp(arr.size(), 0); // temporary vector

    c = mergeSort(arr, temp, 0, arr.size() - 1);
    return 0;
}

int main()
{
    vector<int> arr{2, 1, 4, 8};

    countInverse(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}