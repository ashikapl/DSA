// valid anagram method 1
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s = "rat";
    string t = "cat";

    cout << "Before sorting :- " << s << " " << t << endl;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    cout << "After sorting :- " << s << " " << t << endl;

    if (s == t)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}