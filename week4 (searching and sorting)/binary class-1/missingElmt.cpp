// Find the missing element using binary search //
#include <iostream>
#include <vector>
using namespace std;

int findMissingElement(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;

    while (s <= e)
    {
        int mid = s + (s - e) / 2;

        // Check if the missing element lies on the right side
        if (arr[mid] == mid + 1)
        {
            // Missing element is on the right side
            s = mid + 1;
        }
        else
        {
            // Missing element is on the left side
            e = mid - 1;
        }
    }

    return s + 1;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5, 6, 7, 8, 9};

    int missingElement = findMissingElement(arr);

    cout << "The missing number is:-> " << missingElement << endl;

    return 0;
}