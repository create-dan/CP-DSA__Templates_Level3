
#include <bits/stdc++.h>
using namespace std;
bool isBalancedParentheses(string str)
{

    int n = str.length();
    int i = 0;
    stack<char> st;
    while (i < n)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }
        else
        {
            if (st.empty())
                return false;
            char ch = st.top();
            st.pop();

            if (str[i] == ')' and ch != '(')
                return false;
            if (str[i] == '}' and ch != '{')
                return false;
            if (str[i] == ']' and ch != '[')
                return false;
        }
        i++;
    }

    return st.empty();
}