// loop practice //

#include <iostream>
using namespace std;

int main()
{

    // Print 0 to 10 no...//

    for (int i = 0; i <= 10; i = i + 1)
    {
        cout << i << " ";
    }

    cout << endl;

    // Print 2 table..//

    int n;
    cout << "Enter any no. ";
    cin >> n;

    for (int a = 1; a <= n; a = a + 1)
    {
        cout << a * 2 << " ";
    }

    cout << endl;

    // Print odd no...//

    int x;
    cout << "Enter the no: "
         << " ";
    cin >> x;

    for (int z = 1; z < x; z = z + 2)
    {
        cout << z << " ";
    }

    cout << endl;

    // Print even no..//

   // int num;
    //cout << "Enter no:"
     //    << " ";
    //cin >> num;

    //for (int ap = 2; ap < num; ap = ap + 2)
    //{
        //cout << ap << " ";
   // }

    int j = 0;
    for (;;)
    {
        if (j < 5)
        {
            cout << j;
            j = j + 1;
        }

        cout << endl;
    }
}