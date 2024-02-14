// Remove all the occurence of a subarray
#include <iostream>
#include <string>
using namespace std;

void removeOcc(string &s, string &part)
{
    int found = s.find(part);
    if (found != string::npos)
    {
        string left_part = s.substr(0, found);
        string right_part = s.substr(found + part.size(), s.size());
        s = left_part + right_part;

        removeOcc(s, part);
    }
    else
    {
        return;
    }
}

int main()
{
    string s = "abcdefghabc";
    string part = "abc";

    removeOcc(s, part);

    cout << s << " ";

    return 0;
}