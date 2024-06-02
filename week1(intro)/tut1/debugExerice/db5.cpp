// check Prime no. //

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool isPrime = true;
    for (int i = 2; i < n; i++)
    {
        if (i % n == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
    {
        cout << "Prime";
    }
    else
    {
        cout << "Not Prime";
    }
    return 0;
}