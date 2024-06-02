// Find the sum of pairs //

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{10, 20, 30, 40, 50};
    int sum = 50;

    // Printing the value
    // Outer loop
    for (int i = 0; i < arr.size(); i++)
    {
        int element = arr[i];

        // Every element , transverse to next element
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (element + arr[j] == sum)
                cout << "Pair Found:- "
                     << "(" << element << "," << arr[j] << ")" << endl;
        }
    }
}