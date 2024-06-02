// GCD / HCF (greatest common divisor / Highest common factor)
#include <iostream>
using namespace std;

int gcd(int A, int B)
{
    if (A == 0)
        return B;
    if (B == 0)
        return A;

    while (A > 0 && B > 0)
    {
        if (A > B)
        {
            A = A - B;
        }
        else
        {
            B = B - A;
        }
    }
    return A == 0 ? B : A;
}

int main()
{
    int A = 28;
    int B = 48;

    int ans = gcd(A, B);

    cout << ans << endl;

    return 0;
}