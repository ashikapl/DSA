#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> revCharBridge(int N, vector<string> &ans)
{
    // char currChar = 'A';

    for (int i = 0; i < N; i++)
    {
        string output = "";
        for (int j = 0; j < N - i; j++)
        {
            output.push_back('*');
        }
        ans.push_back(output);
    }
    return ans;
}

int main()
{
    int N = 5;
    vector<string> ans;

    revCharBridge(N, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}