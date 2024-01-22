class Solution
{
    public:
        vector<int> findErrorNums(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> ans;
            vector<int> freq(n + 1);
            for (int x: nums)
            {
                freq[x ]++;
            }
            for (int i = 1; i <= n; i++)
            {
                if (freq[i] == 2)
                {
                    ans.push_back(i);
                    break;
                }
            }
            for (int i = 1; i <= n; i++)
            {
                if (freq[i] == 0)
                {
                    ans.push_back(i);
                    return ans;
                }
            }
            return ans;
        }
};