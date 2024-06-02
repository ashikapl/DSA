// Insertion Sort //
// we have multiple elements in an array we have to place them on their right position by following this 4 steps given below //
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{1, 7, 6, 4, 5, 3, 2};
    int n = arr.size();

    for (int round = 1; round < n; round++)
    {
        // Step 1 - fetch (store)
        int val = arr[round];
        int j = round - 1;
        for (; j >= 0; j--)
        {
            // step 2 - compare
            if (arr[j] > val)
            {
                // step 3 - shifting
                arr[j + 1] = arr[j];
            }
            else
            {
                // rukna hai
                break;
            }
        }
        // step 4 - copy
        arr[j + 1] = val;
    }

    // print
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}