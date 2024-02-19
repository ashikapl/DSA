// Quick Sort
#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    // step: 1 -> select pivot index
    int pivotIndex = s;
    int pivotElement = arr[s];

    // step: 2 -> put on right position
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivotElement)
            count++;
    }

    // jb loop khtm hoga to hum apni right position pr honge
    int rightIndex = s + count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

    // step: 3 -> put chote element in left and bade in right
    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement)
        {
            i++;
        }
        while (arr[j] > pivotElement)
        {
            j--;
        }

        // now there is 2 cases are possible
        // A -> you found the element to swap
        // B -> no need to swap if all the elements are right means chote from pivot in left and bade in right
        if (i < pivotIndex && i > pivotIndex)
            swap(arr[i], arr[j]);
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // partition logic
    int p = partition(arr, s, e);

    // recursion call
    // for left sort
    quickSort(arr, s, p - 1);

    // for right sort
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {8, 1, 5, 6, 30, 50};
    int n = 6;

    int s = 0;
    int e = n - 1;

    quickSort(arr, s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}