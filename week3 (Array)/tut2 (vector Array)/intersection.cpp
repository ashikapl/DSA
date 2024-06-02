// Find Intersection of 2 arrays //

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{2, 4, 6, 6, 8};
    int sizeArr = arr.size();

    vector<int> brr{1, 2, 3, 4};
    int sizeBrr = brr.size();

    vector<int> ans;

    // Outer loop
    for (int i = 0; i < sizeArr; i++)
    {
        int element = arr[i];

        // inner loop to check common value
        for (int j = 0; j < sizeBrr; j++)
        {
            if (element == brr[j])
            {
                // mark the element because same value double print na ho
                brr[j] = INT_MIN;
                ans.push_back(element);
            }
        }
    }

    // printing the value
    cout << "Intersection is: --> ";
    for (auto value : ans)
    {
        cout << value << " ";
    }
}