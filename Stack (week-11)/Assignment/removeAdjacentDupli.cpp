// Remove adjacent Duplicates from string using stack
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string rremove(string s)
{

    stack<char> st;
    for (auto ch : s)
    {
        if (!st.empty() && st.top() == ch)
        {
            st.pop();
        }
        else
        {
            st.push(ch); // Pass the character 'ch' to push function
        }
    }
    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string input = "abbaca";

    string ans = rremove(input);
    cout << "Result: " << ans << endl;
    return 0;
}
