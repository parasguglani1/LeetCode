class Solution
{
    public:
        string reverseParentheses(string s)
        {
            stack<string> st;
            string ans;

            for (char ch: s)
            {
                if (ch == '(')
                {
                    st.push(ans);
                    ans = "";
                }
                else if (ch == ')')
                {
                    reverse(ans.begin(), ans.end());
                    ans = st.top() + ans;
                    st.pop();
                }
                else
                {
                    ans += ch;
                }
            }

            return ans;
        }
};