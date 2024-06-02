// print digits of a number // In case of 0647 number the digits are print 4 2 3 becoz its in octal(base 8)no.
#include <iostream>
using namespace std;

void printDigits(int n)
{
    // base case
    if (n == 0)
        return;

    // R.R - baaki recursionn smbhl lega
    printDigits(n / 10);

    // 1 case mein solve karlu
    int digit = n % 10;
    cout << digit << " ";
}

int main()
{
    int n = 647;

    printDigits(n);

    return 0;
}