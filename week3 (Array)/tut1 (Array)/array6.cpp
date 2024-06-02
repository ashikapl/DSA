// check maximum and minimum value in array with linear search

#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int arr[] = {23, 50, 22, 54, 72, 27, 12, 56, 64, 21};
    int size = 10;

    // Inilialize max
    int max = INT_MIN;
    int mini = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < mini)
        {
            // found the no which is greater than max, then update max
            mini = arr[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            // found the no which is greater than max, then update max
            max = arr[i];
        }
    }

    cout << "The minimum number is: " << mini << endl;
    cout << "The Max value is:- " << max << endl;

    return 0;
}