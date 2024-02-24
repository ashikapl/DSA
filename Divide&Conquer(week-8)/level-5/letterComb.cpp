// Letter combination of phone numbers
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void letterCombination(string digits, int index, string output, vector<string> &ans, vector<string> &mapping)
{
    // base case
    if (index >= digits.length() || digits.length() == 0)
    {
        ans.push_back(output);
        return;
    }

    // solve one case
    char digitChar = digits[index];
    int digitInteger = digitChar - '0'; // it convert char into integer

    string value = mapping[digitInteger];

    for (int i = 0; i < value.length(); i++)
    {
        char ch = value[i];

        // include
        output.push_back(ch);
        // recursive call
        letterCombination(digits, index + 1, output, ans, mapping);
        // backTrack
        output.pop_back();
    }
}

int main()
{
    string digits = "23";

    vector<string> ans;

    int index = 0;
    string output = "";

    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    letterCombination(digits, index, output, ans, mapping);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}