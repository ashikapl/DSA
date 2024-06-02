// Find Triplet sum //

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{10, 20, 30, 40, 50};
    int sum = 80;

    // Outer loop for 1st value  eg -- (x, y, z) Its for x value
    for (int i = 0; i < arr.size(); i++)
    {
        int element1 = arr[i];

        // Inner loop for 2nd value eg -- for y
        for (int j = i + 1; j < arr.size(); j++)
        {
            int element2 = arr[j];

            // Inner loop for 3rd value eg -- for z
            for (int k = j + 1; k < arr.size(); k++)
            {
                int element3 = arr[k];

                if (element1 + element2 + element3 == sum)
                {
                    cout << "(" << element1 << "," << element2 << "," << element3 << ")" << endl;
                }
            }
        }
    }
}