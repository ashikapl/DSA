#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {2, 4, 6, 8, 10};

    cout << *arr << endl;       //  2 - first element value
    cout << arr[0] << endl;     // 2
    cout << *arr + 1 << endl;   // 2+1 = 3
    cout << *(arr) + 1 << endl; // 2 +1 = 3
    cout << *(arr + 1) << endl; // Address of second element = 4
    cout << arr[1] << endl;     // 4
    cout << *(arr + 2) << endl; // adrs of third element = 6
    cout << arr[2] << endl;     // 6
    cout << *(arr + 3) << endl; // adrs of 4th element = 8
    cout << arr[3] << endl;     // 8

    return 0;
}