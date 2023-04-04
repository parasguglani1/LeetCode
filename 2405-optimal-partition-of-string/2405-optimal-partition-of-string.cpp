class Solution
{
    public:

        int partitionString(string s)
        {
            int flag = 0;
            int n = s.size();
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                int curr = s[i] - 'a';
                if (flag &1 << curr)
                {
                    ans++;
                    flag = 0;
                }
                flag = flag | (1 << curr);
            }
            return ans + 1;
        }
};