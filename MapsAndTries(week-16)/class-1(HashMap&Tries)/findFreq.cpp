// Find the frequency of string
#include<iostream>
#include<string>
#include<unordered_map> 
using namespace std;

int main()
{
    string s = "thiruvananthpuram";
    unordered_map<char,int> freq;

    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        freq[ch]++;
    }

    cout << "Entry of Frequency map"<< endl;
    for(auto i:freq)
    {
        cout << i.first << "-> " << i.second << endl;
    }

    return 0;
}