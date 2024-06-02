// Counting from 1 to N //

#include <iostream>
using namespace std;

void printNum(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the value ";
    cin >> n;

    printNum(n);

    return 0;
}