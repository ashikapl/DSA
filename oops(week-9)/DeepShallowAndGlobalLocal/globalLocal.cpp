// Global and Local Variables
#include <iostream>
using namespace std;

int a = 5; // Global Variable

void fun()
{
    int a = 23; // local to fun() function only
    cout << a << endl;
    ::a = 1;
    cout << ::a << endl; // Global to any function
}

int main()
{
    int a = 10;          // Local variable of main() function only
    cout << a << endl;   // it can access only in main function
    ::a = 40;            // we can change global varible value also at same memoru location
    cout << ::a << endl; // But global varibles can access any function

    fun();

    return 0;
}