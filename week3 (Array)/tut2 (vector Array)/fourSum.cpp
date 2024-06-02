// Sum of Four no. (x, y, z, p)

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{10, 20, 30, 40, 50};
    int sum = 100;

    // Outer loop for 1st value X
    for (int i = 0; i < arr.size(); i++)
    {
        int element1 = arr[i];

        // inner loop for 2nd value Y
        for (int j = i + 1; j < arr.size(); j++)
        {
            int element2 = arr[j];

            // for 3rd value Z
            for (int k = j + 1; k < arr.size(); k++)
            {
                int element3 = arr[k];

                // for 4th value P
                for (int p = k + 1; p < arr.size(); p++)
                {
                    int element4 = arr[p];

                    if (element1 + element2 + element3 + element4 == sum)
                    {
                        cout << "(" << element1 << "," << element2 << "," << element3 << "," << element4 << ")" << endl;
                    }
                }
            }
        }
    }
}