// Custom Comparetor
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(char first, char second)
{
    return first > second; // this > sign sort the elements in descending order
    // return first < second this < sign sort the elements in ascending order
}

bool compare(int a, int b)
{
    return a > b;
}

bool customComparetor(string x, string y)
{ // it's compartion is based on algorithm of sort funtion
    cout << "x is:-> " << x;
    cout << " y is:-> " << y << endl;
    return x > y; // from last to first z to a reverse
}

int main()
{
    string str = "xbzayc";
    sort(str.begin(), str.end(), cmp);

    vector<int> arr{1, 4, 5, 3, 2};
    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << str;

    cout << endl;

    vector<string> s = {"goa", "mumbai", "agra", "bhopal"};
    sort(s.begin(), s.end(), customComparetor);

    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }

    return 0;
}