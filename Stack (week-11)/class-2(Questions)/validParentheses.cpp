// Check valid parentheses
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // opening brackets
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else // closing brackets
        {
            if (!st.empty())
            {
                int topCh = st.top();
                if (ch == ')' && topCh == '(')
                {
                    st.pop();
                }
                else if (ch == '}' && topCh == '{')
                {
                    st.pop();
                }
                else if (ch == ']' && topCh == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "[{()}]";

    bool ans = isValid(s);

    if (ans == true)
    {
        cout << "Valid Parentheses!" << endl;
    }
    else
    {
        cout << "Not Valid!" << endl;
    }

    return 0;
}