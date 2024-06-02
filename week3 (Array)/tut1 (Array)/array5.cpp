// with the help of linear search operation count zeros and ones

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 2, 3, 4, 5};
    int size = 10;

    int countZeroes = 0;
    int countOnes = 0;

    for (int i = 0; i < size; i++)
    {

        // if found zero so increment the int zeroes
        if (arr[i] == 0)
        {
            countZeroes++;
        }

        // if found one so increment the int ones
        if (arr[i] == 1)
        {
            countOnes++;
        }
    }

    cout << "Number of zeroes: " << countZeroes << endl;
    cout << "Number of ones: " << countOnes << endl;

    return 0;
}