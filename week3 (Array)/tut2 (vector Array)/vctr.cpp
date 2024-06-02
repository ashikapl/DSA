// take input and put value //

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value: ";
    cin >> n;

    vector<int> arr(n, -104);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Size of array: " << arr.size() << endl;
    cout << "Capacity of array: " << arr.capacity() << endl;

    cout << endl;

    cout << "Printing the brr --->" << endl;

    vector<int> brr{10, 20, 30};

    for (int j = 0; j < brr.size(); j++)
    {
        cout << brr[j] << " ";
    }
    cout << endl;

    cout << "Vector brr is empty or not: " << arr.empty();

    return 0;
}