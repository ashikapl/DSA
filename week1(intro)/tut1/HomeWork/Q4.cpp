//print counting from N to 1

#include <iostream>
using namespace std;

int main()
{

    int n;

    cout << "Enter any number" << endl;
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        cout << i << " ";
    }

    return 0;

}