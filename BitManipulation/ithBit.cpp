// Get the ith bit of a number 
#include<iostream>
using namespace std;

int getithBit(int n, int i)
{
    int mask = n << i; // here we shift the ith bit in n to create a new number(mask) eg -> 00000...1000
    int ans = n & mask;  // then and with that number so ith bit is found 
    if(ans == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int n = 10;
    int i = 2;

    int ans = getithBit(n,i);
    cout << "ith bit is: " << ans << endl;

    return 0;
}