// Check square of the number //
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value: " << endl;
    cin >> n;

    bool flag = false;
    for (int i = 1; i <= n / 2; i++)
    {
        if (i ^ 2 == n)
        {
            flag = true;
            cout << "True";
            break;
        }
        else
        {
            cout << "False";
        }
    }

    return 0;
}