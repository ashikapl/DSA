// Count Inverse problem using merge sort (algo)
#include <iostream>
#include <vector>
using namespace std;

long countInverse(vector<int> &arr)
{
    long c = 0;
    vector<int> temp(arr.size(), 0); // temporary vector

    mergeSort(arr, temp, 0, arr.size() - 1);
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