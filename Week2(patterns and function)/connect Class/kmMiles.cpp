// Convert kilometers into miles //

#include <iostream>
using namespace std;

int main()
{

    int km;
    cout << "Enter the value of KM: ";
    cin >> km;

    cout << "Value in miles is: " << (1 / 1.609) * km << endl;

    return 0;
}