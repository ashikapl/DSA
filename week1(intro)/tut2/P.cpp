// type Casting//

#include <iostream>
using namespace std;

int main()
{

    // Automatic or called Implicit ex.. //

    int num = 'a';
    cout << num << endl;

    float num1 = 2;
    cout << num1 << endl;

    char ch = 97;
    cout << ch << endl;
    cout << endl;

    // manually or called Explicit ex.. //

    int name = char('d');
    cout << name << endl;

    int fly = float(2.5);
    cout << fly << endl;

    char fly1 = int(120);
    cout << fly1 << endl;
    cout << endl;

    // size of variable //

    int i;
    cout << sizeof(i) << endl;

    int z = 10;
    cout << sizeof(z) << endl;
    cout << endl;

   // Taking input //

   int a;
   cout << " Enter a no. " << endl;
   cin >> a;

   cout << " You Entered " << " "  << a << endl;

}


