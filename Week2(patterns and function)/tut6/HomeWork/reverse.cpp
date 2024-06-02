// Reverse an Integer //

#include <iostream>
using namespace std;

void reverseInt(int n)
{
    for (int i = n; i >= 1; i--)
    {
        cout << i << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    reverseInt(n);

    return 0;
}