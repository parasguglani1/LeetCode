class Solution
{
    public:
        string findDifferentBinaryString(vector<string> &nums)
        {
            int n = nums.size();
            set<string> st;
            for (auto x: nums)
            {
                st.insert(x);
            }

           	//make all strings

            string str = "";
            for (int i = 0; i < n; i++)
            {
                str += '0';
            }
            for (int i = 0; i < n; i++)
            {
                if (st.find(str) == st.end())
                {
                    return str;
                }
                str[i] = '1';
            }
            return str;
        }
};