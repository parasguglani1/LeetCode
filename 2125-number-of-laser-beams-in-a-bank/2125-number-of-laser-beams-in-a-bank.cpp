class Solution
{
    public:
        int numberOfBeams(vector<string> &bank)
        {
            int n = bank.size();
            int ans = 0;
            int prev = count(bank[0].begin(), bank[0].end(), '1');
            for (int i = 1; i < n; i++)
            {
                int cur = count(bank[i].begin(), bank[i].end(), '1');
                if (cur != 0)
                {
                    ans += cur * prev;
                    prev = cur;
                }
            }
            return ans;
        }
};