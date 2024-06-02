// Bubble Sort //
// har ith round main ith largest element ko uski right position pr place karta hain using swap //
// Time Complexity -> O(n^2) //

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{10, 12, 3, 2, 1, 6, 7};
    int n = arr.size();

    for (int round = 1; round < n; round++)
    {
        bool swapped = false;
        for (int j = 0; j < n - round; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (swapped == false)
        {
            // agr array sort ho chuka he to loop ko khtm kr do
            break;
        }
    }

    // print
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}