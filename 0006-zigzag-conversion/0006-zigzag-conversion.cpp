class Solution
{
    public:
        string convert(string s, int numRows)
        {
            int n = s.length();
            string ans = "";
            if (numRows == 1 || n <= 2)
            {
                return s;
            }
            ans.resize(s.length());
            int currow = 1;
            int currindex = 0;
            int i = 0;
            int row = numRows - 1;
            int row2 = 0;
            bool desc = false;
            while (i < n)
            {
                int add = (row) + (row);
                int add2 = 2 * row2;
                int added = 0;

                while (currindex < n)
                {
                    ans[i++] = s[currindex];
                    if (desc)
                    {
                        added = add2;
                    }
                    else
                    {
                        added = add;
                    }

                    currindex = added + currindex;
                    if (row2 > 0 && row2 < numRows - 1 && currindex < n)
                    {
                        desc = desc ^ 1;
                    }
                }
                desc = false;
                row--;
                currindex = numRows - row - 1;
                row2++;
                if (row2 == numRows - 1)
                {
                    desc = true;
                }
            }
           	// cout<<ans.length();
           	// if (ans.length() != s.length())
           	//     return s;
            return ans;
        }
};