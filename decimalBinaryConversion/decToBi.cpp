// Convert Decimal to binary in two different methods //

#include <iostream>
#include <cmath>
using namespace std;

// Method 1st..
int decimalToBinarymethod1(int n)
{
    // Division method
    int binaryNo = 0;
    int i = 0;
    while (n > 0)
    {
        int bit = n % 2;
        binaryNo = bit * pow(10, i++) + binaryNo;
        n = n / 2;
    }

    return binaryNo;
}

// Method 2nd..
int decimalToBinarymethod2(int n)
{
    // Bitwise method

    // n = 10 = 1010
    int binaryNo = 0;
    int i = 0;
    while (n > 0)
    {
        int bit = (n & 1);
        binaryNo = bit * pow(10, i++) + binaryNo;
        n = n >> 1;
    }

    return binaryNo;
}

int main()
{
    int n;
    cin >> n;

    // int binary = decimalToBinarymethod1(n);

    int binary = decimalToBinarymethod2(n);

    cout << binary;

    return 0;
}