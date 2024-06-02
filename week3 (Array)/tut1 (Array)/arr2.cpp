#include <iostream>
using namespace std;

int main()
{
    // char a[5];
    // cout << "First name ";
    // cin >> a;
    // cout << "First name is " << a << endl;

    // float a, b, c;
    // cin >> a;
    // cin >> b;
    // c = a + b;
    // cout << c;

    int num, i, count = 0;
    cout << "enter the number to checked ";
    cin >> num;
    if (num == 0)
    {
        cout << endl
             << num << " is not prime number";
    }
    else
    {
        for (i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                count++;
            }
        }
        if (count > 0)
        {
            cout << endl
                 << num << " is not prime number";
        }
        else
        {
            cout << endl
                 << num << " is prime number";
        }
    }

    return 0;
}

// multiple functions using //

// int a, b, c, sum, sub, multi, div, mod;
// cout << "Enter the value of a, b, c: ";
// cin >> a >> b >> c;

// sum = a + b + c;
// cout << "The sum is: " << sum << endl;

// sub = a - b - c;
// cout << "The subtraction is: " << sub << endl;

// multi = a * b * c;
// cout << "The multiplication is:  " << multi << endl;

// div = a / b / c;
// cout << "The division is: " << div << endl;

// mod = a % b % c;
// cout << "The modulas is: " << mod << endl;

// Swapping

// int a, b, temp;
// cout << "Value of a: ";
// cin >> a;
// cout << "Value of b: ";
// cin >> b;
// cout << "Before swapping value of a : " << a << endl;
// temp = a;
// a = b;
// b = temp;
// cout << "After swapping value of b: " << a;

//     return 0;
// }