class Solution
{
    public:
        vector<int> minOperations(string s)
        {
            int N = s.size(), sum = 0, right = 0, left = 0;
            vector<int> ans(s.size());
            for (int i = 0; i < N; ++i)
            {
                if (s[i] == '1') sum += i, ++right;
            }
            for (int i = 0; i < N; ++i)
            {
                ans[i] = sum;
                if (s[i] == '1') --right, ++left;
                sum += left - right;
            }
            return ans;
        }
};