// Print the digits of a no. //

#include <iostream>
using namespace std;

int main()
{

    int n = 524;

    while (n != 0)
    {
        int remainder = n % 10;
        cout << remainder << " ";

        n = n / 10;
    }

    cout << endl;

    // We can also write is code in For loop //

    int i = 528;

    for (; i != 0; i = i / 10)
    {
        int rem = i % 10;
        cout << rem << " ";
    }

    return 0;
}