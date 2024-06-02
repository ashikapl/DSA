// find the first repeated element //
#include <iostream>
#include <unordered_map>
using namespace std;

int firstRepeated(int arr[], int size)
{
    // for (int i = 0; i < size; i++)
    // {
    //     bool firstRepeated = false;
    //     for (int j = i + 1; j < size; j++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             firstRepeated = true;
    //             return i + 1;
    //         }
    //     }
    // }

    // Hashing method with unordered list
    unordered_map<int, int> hash;
    for (int i = 0; i < size; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 0; i < size; i++)
    {
        if (hash[arr[i]] > 1)
            return i + 1;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 5, 3, 4, 3, 5, 6};
    int size = 7;

    cout << "The first index repeated is:- " << firstRepeated(arr, size);

    return 0;
}