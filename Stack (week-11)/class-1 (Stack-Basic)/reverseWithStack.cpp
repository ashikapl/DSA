// Reverse a string with the help of string
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str = "Ashika";

    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}