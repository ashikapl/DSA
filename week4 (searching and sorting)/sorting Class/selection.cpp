// Selection sorting with help of linear search
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{2, 4, 7, 5, 6, 1, 3};
    int n = arr.size();

    // outer loop -> 0 to n-1 means 0 to size-1 to find minimum
    for (int i = 0; i < n - 1; i++)
    {
        int miniIndex = i;

        // inner loop -> i+1 to n means minimum ke aage wale element se j ka loop last tak chlega
        for (int j = i + 1; j < n; j++)
        {
            if (arr[miniIndex] > arr[j])
                // jb humare miniIndex se bhi chota element mil jaye
                miniIndex = j;
        }

        swap(arr[i], arr[miniIndex]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}