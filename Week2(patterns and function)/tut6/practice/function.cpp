// Write a function to add 2 numbers //

#include <iostream>
using namespace std;

int add(int a, int b);
// {
//     int result = a + b;
//     return result;
// }

int main()
{
    int a;
    int b;
    cout << "Enter a and b : ";
    cin >> a >> b;

    int sum = add(a, b);

    cout << "Addition of a and b is: " << sum << endl;

    return 0;
}

int add(int a, int b)
{
    int result = a + b;
    return result;
}
