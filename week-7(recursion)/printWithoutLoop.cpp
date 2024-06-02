#include <iostream>
using namespace std;

void print(int N)
{
    // base case
    if (N <= 0)
        return;

    // Recursive Relation
    print(N - 1);

    // processing
    cout << N << " ";
}

int main()
{
    int N;
    cin >> N;

    print(N);

    return 0;
}