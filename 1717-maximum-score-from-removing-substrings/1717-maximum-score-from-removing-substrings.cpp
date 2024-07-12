class Solution
{
    public:
        int removeStr(string &s, string rem)
        {
            stack<char> st;
            int cnt = 0;
            for (char c: s)
            {
                if (!st.empty() && st.top() == rem[0] && c == rem[1])
                {
                    st.pop();
                    cnt++;
                }
                else
                {
                    st.push(c);
                }
            }
            string res = "";
            while (!st.empty())
            {
                res += st.top();
                st.pop();
            }
            reverse(res.begin(), res.end());
            s = res;
            return cnt;
        }
    int maximumGain(string s, int x, int y)
    {

        int topscore = x;
        string rem1 = "ab";

        int lessscore = y;
        string rem2 = "ba";

        if (x < y)
        {
            swap(topscore, lessscore);
            swap(rem1, rem2);
        }

       	//remove rem1 first then remove rem2

        int ans = removeStr(s, rem1) *topscore;
        ans += removeStr(s, rem2) *lessscore;
        return ans;
    }
};
// aaabbbaaa