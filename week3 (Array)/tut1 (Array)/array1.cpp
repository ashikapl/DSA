// Taking input and printing the array values

#include <iostream>
using namespace std;

int main()
{
    int arr[100];

    int n;
    cout << "How many number you want to add in array:-- ";
    cin >> n;

    cout << "Enter the number: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Printing the values in double

    cout << "doubles: ";
    for (int i = 0; i < n; i++)
    {
        cout << 2 * arr[i] << " ";
    }
}