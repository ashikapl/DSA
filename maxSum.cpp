#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 4, 6, -9};
    int n = 4;

    int maxSum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        // for (int j = i; j < n; j++)
        // {

        // for (int k = i; k <= j; k++)
        // {
        //     // cout << arr[k] << " ";
        //     sum += arr[k];
        //     if (sum > maxSum)
        //     {
        //         maxSum = sum;
        //     }
        // }
        // // cout << endl;
        // sum = 0;
        // cout << arr[j] << " ";
        sum += arr[i];
        if (sum > maxSum)
        {
            maxSum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
        // }
        // cout << endl;
    }

    cout << maxSum;

    return 0;
}