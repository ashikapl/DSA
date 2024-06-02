// Binary - search an element with using an in-built function called binary-search and without binary-funtion //
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// without the use of binary-funtion found the target with the help of a funtion //
int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int element = arr[mid];

        if (element == target)
        {
            return mid;
        }
        else if (target < element)
        {
            // search in left
            end = mid - 1;
        }
        else
        {
            // search in right
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = 8;
    int target = 12;

    int targetFound = binarySearch(arr, size, target);

    // without the use of binary-funtion found the target with the help of a funtion //
    if (targetFound == -1)
    {
        cout << "Target is not found !" << endl;
    }
    else
    {
        cout << "Target is found at index:- " << targetFound << endl;
    }

    // with using binary-function
    // in an array
    int A[] = {1, 2, 3, 4, 5};
    int n = 9;

    if (binary_search(A, A + n, 5)) // here n is present the size of an array
    {
        cout << "Found by binary-search funtion in array" << endl;
    }
    else
    {
        cout << "Not Found by binary-search funtion in array" << endl;
    }

    // vector array
    vector<int> v{1, 3, 5, 7, 9};

    if (binary_search(v.begin(), v.end(), 2))
    {
        cout << "Found by binary-search funtion in vector array";
    }
    else
    {
        cout << "Not Found by binary-search funtion in vector array";
    }

    return 0;
}