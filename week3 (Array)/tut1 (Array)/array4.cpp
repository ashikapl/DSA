// check

// In linear search operation

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = 8;

    int key;
    cout << "Enter the no. ";
    cin >> key;

    bool flag = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            // found
            flag = 1;
        }
    }

    if (flag)
    {
        cout << "Found";
    }

    else
    {
        cout << "Not Found";
    }
}