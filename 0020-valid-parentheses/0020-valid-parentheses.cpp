class Solution
{
    public:
        bool isValid(string s)
        {
            stack<char> st;
            int n = s.size();
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    st.push(s[i]); continue;
                }
                if(st.empty())
                {
                    return false;
                }
                
                if (s[i] == '}')
                {
                    if (st.top() == '{')
                        st.pop();
                    else
                        return false;
                }
                if (s[i] == ']')
                {
                    if (st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
                if (s[i] == ')')
                {
                    if (st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                        return false;
                }
            }
            if(st.empty())
            {
                return true;
            }
            return false;
        }
};