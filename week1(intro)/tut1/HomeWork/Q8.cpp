//printing 1 to n but only even no.

#include <iostream>
using namespace std;

int main()
{

    int n;

    cout<<"Enter any No."<<endl;
    cin>>n;

    for (int i = 2; i<=n; i+=2)
    {
        cout << i<<" ";
    }

    return 0;
}