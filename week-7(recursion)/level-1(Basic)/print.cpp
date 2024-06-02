// print reverse and straight counting using recursion
#include <iostream>
using namespace std;

void printReverse(int n)
{
    // base case
    if (n == 0)
        return;

    // processing
    cout << n << " ";

    // recursive relation
    printReverse(n - 1);
}

void printStraight(int n)
{
    // B.C
    if (n == 0)
        return;

    // R.R
    printStraight(n - 1);

    // processing
    cout << n << " ";
}

int main()
{
    int n;
    cout << "Enter the number:- ";
    cin >> n;

    cout << "Reverse counting:- ";
    printReverse(n);

    cout << endl;

    cout << "Straight counting:- ";
    printStraight(n);

    return 0;
}