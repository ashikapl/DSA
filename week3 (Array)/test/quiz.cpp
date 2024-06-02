#include <iostream>
using namespace std;

int main()
{
    int array1[] = {1200, 200, 2300, 1230, 1543};
    int array2[] = {12, 14, 16, 18, 20};
    int temp, result = 0;

    for (temp = 0; temp < 5; temp++)
    {
        result += array1[temp];
    }
    for (temp = 0; temp < 4; temp++)
    {
        result += array2[temp];
    }

    cout << result;

    return 0;
}