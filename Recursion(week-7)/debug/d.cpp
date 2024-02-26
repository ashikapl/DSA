#include <iostream>
using namespace std;

int rec(char input[], int n)
{
    if (input[0] == '\0')
        return n;
    n = n * 10 + input[0] - 48;
    return rec(input + 1, n);
}

int stringToNumber(char input[])
{
    int n = 0;
    return rec(input, n);
}

int main()
{
    char input[] = "ranu";

    int ans = stringToNumber(input);

    cout << ans << " ";

    return 0;
}