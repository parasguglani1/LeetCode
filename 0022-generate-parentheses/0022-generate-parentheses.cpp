class Solution
{
    public:

        vector<string> generateParenthesis(int n)
        {
            vector<string> ans;
            set<string> st;
            int sz = 1;
            string p = "()";
            st.insert(p);
            while (sz < n)
            {
                set<string> newst;
                for (auto str: st)
                {

                    for (int i = 0; i < str.size(); i++)
                    {
                        string curr = str.substr(0, i);
                        curr += p;
                        curr += str.substr(i);
                        newst.insert(curr);
                    }
                }
                st = newst;
                sz++;
            }
            ans.assign(st.begin(), st.end());
            return ans;
        }
};