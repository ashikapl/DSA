#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    cout << "The value of the third element in arr is " << *(ptr + 2) << endl;
    return 0;
}