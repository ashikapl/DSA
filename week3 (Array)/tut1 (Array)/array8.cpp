// Reverse or Swapping the array

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        // Step: 1
        swap(arr[start], arr[end]);

        // Step: 2
        start++;

        // Step: 3
        end--;
    }

    // Printing array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}