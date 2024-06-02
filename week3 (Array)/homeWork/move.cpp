// move all negative digits on left side //
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 3, -3, 4, -1, 2};
    int size = 6;
    int l = 0;
    int h = size - 1;

    for (int i = 0; i < size; i++)
    {
        if (arr[l] < 0)
        {
            l++;
        }
        else if (arr[h] > 0)
        {
            h--;
        }
        else
        {
            swap(arr[l], arr[h]);
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}