#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
using namespace std;

vector<string> solve(string configuration)
{
    vector<string> v;
    string temp = "";
    for (int i = 0; i < configuration.length(); i++)
    {
        if (configuration[i] != '|')
        {
            temp += configuration[i];
        }
        else
        {
            v.push_back(temp);
            temp = "";
        }
    }
    // Push the last substring
    v.push_back(temp);
    return v;
}

vector<string> ordered_configuration(string configuration)
{
    vector<string>v = solve(configuration);
     map<string, string> mp;
    for (int i = 0; i < v.size(); i++)
    {
        string s1 = v[i].substr(4, 10);
        string s2 = v[i].substr(0, 4);
        mp[s2] = s1;
    }

    sort(v.begin(),v.end());
    vector<string> ans;
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
  return ans;
}

int main()
{

    string str = "0001LAJ5KBX9H8|0003UKURNK403F|0002M06K1ZPWFA|0004OWRXZFMS2C";
    vector<string> v = ordered_configuration(str);
    
   

    // Print the ans in the required format
    cout << "[";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << "\"" << v[i] << "\"";
        if (i != v.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}