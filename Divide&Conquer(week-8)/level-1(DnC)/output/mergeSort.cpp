// merge sort -> IMP question
#include <iostream>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;

    // length of both the array create
    int len1 = mid - s + 1;
    int len2 = e - mid; // e - mid - 1 + 1 here 1 and 1 are cancel out

    // assume two array pointer
    int *left = new int[len1];
    int *right = new int[len2];

    // copy
    int k = s; // from starting
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1; // from other remaining array
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // merge both the copyed arrays

    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s; // main array index start from s

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else
        {
            arr[mainArrayIndex++] = right[rightIndex++];
        }
    }

    // if one array is over than copy the remaining elements
    while (leftIndex < len1)
    {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    while (rightIndex < len2)
    {
        arr[mainArrayIndex++] = right[rightIndex++];
    }

    // TODO : we can delete this copy created arrays
}

void mergeSort(int arr[], int s, int e)
{
    // base case -> s==e means single element in array and s > e is invalid array
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    // left half array sort
    mergeSort(arr, s, mid);

    // right half array sort
    mergeSort(arr, mid + 1, e);

    // merge both sorted array
    merge(arr, s, e);
}

int main()
{
    int arr[] = {2, 1, 1, 4, 9, 8, 8};
    int n = 7;

    int s = 0;
    int e = n - 1;

    mergeSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}