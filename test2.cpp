#include <iostream>
using namespace std;

void fun(int a)
{
    if (a < 0)
        return;

    fun(a--);

    cout << a << " ";
}

int main()
{
    int a = 3;
    fun(a);

    return 0;
}