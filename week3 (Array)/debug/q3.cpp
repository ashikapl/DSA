#include <iostream>
using namespace std;
void moveNegative(int arr[], int n)
{
    int start = 0, end = n - 1;
    while (start < end)
    {
        while (arr[start] < 0 && start < end)
        { // swap when a positive element is encountered
            cout << arr[start] << endl;
            start++;
        }
        while (arr[end] > 0 && start < end)
        { // swap when a negative element is encountered
            cout << arr[end] << endl;
            end--;
        }
        if (start < end)
        {
            swap(arr[start], arr[end]); // swap the elements
            start++;
            end--;
        }
    }
}
int main()
{
    int n = 5;
    int arr[n] = {2, -3, -1, 5, -4};
    moveNegative(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}