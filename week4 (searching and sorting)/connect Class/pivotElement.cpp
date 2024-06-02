// Pivot element
// there are two condition in pivot element that (1) array be sorted and rotated (2) no duplicate
#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (s == e)
        {
            // single element
            return s;
        }
        else if (arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid - 1] > arr[mid])
        {
            return mid - 1;
        }
        else if (arr[s] > arr[mid]) // here s is starting element
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr{2, 4, 6, 8, 9, 10};

    int ans = findPivot(arr);

    cout << "Index of pivot element is:--> " << ans << endl;
    cout << "The pivot element is:--> " << arr[ans] << endl;

    return 0;
}