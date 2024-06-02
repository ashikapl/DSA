// check size

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;

    cout << arr.size() << endl;

    arr.push_back(4);
    arr.push_back(6);

    // Print
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}