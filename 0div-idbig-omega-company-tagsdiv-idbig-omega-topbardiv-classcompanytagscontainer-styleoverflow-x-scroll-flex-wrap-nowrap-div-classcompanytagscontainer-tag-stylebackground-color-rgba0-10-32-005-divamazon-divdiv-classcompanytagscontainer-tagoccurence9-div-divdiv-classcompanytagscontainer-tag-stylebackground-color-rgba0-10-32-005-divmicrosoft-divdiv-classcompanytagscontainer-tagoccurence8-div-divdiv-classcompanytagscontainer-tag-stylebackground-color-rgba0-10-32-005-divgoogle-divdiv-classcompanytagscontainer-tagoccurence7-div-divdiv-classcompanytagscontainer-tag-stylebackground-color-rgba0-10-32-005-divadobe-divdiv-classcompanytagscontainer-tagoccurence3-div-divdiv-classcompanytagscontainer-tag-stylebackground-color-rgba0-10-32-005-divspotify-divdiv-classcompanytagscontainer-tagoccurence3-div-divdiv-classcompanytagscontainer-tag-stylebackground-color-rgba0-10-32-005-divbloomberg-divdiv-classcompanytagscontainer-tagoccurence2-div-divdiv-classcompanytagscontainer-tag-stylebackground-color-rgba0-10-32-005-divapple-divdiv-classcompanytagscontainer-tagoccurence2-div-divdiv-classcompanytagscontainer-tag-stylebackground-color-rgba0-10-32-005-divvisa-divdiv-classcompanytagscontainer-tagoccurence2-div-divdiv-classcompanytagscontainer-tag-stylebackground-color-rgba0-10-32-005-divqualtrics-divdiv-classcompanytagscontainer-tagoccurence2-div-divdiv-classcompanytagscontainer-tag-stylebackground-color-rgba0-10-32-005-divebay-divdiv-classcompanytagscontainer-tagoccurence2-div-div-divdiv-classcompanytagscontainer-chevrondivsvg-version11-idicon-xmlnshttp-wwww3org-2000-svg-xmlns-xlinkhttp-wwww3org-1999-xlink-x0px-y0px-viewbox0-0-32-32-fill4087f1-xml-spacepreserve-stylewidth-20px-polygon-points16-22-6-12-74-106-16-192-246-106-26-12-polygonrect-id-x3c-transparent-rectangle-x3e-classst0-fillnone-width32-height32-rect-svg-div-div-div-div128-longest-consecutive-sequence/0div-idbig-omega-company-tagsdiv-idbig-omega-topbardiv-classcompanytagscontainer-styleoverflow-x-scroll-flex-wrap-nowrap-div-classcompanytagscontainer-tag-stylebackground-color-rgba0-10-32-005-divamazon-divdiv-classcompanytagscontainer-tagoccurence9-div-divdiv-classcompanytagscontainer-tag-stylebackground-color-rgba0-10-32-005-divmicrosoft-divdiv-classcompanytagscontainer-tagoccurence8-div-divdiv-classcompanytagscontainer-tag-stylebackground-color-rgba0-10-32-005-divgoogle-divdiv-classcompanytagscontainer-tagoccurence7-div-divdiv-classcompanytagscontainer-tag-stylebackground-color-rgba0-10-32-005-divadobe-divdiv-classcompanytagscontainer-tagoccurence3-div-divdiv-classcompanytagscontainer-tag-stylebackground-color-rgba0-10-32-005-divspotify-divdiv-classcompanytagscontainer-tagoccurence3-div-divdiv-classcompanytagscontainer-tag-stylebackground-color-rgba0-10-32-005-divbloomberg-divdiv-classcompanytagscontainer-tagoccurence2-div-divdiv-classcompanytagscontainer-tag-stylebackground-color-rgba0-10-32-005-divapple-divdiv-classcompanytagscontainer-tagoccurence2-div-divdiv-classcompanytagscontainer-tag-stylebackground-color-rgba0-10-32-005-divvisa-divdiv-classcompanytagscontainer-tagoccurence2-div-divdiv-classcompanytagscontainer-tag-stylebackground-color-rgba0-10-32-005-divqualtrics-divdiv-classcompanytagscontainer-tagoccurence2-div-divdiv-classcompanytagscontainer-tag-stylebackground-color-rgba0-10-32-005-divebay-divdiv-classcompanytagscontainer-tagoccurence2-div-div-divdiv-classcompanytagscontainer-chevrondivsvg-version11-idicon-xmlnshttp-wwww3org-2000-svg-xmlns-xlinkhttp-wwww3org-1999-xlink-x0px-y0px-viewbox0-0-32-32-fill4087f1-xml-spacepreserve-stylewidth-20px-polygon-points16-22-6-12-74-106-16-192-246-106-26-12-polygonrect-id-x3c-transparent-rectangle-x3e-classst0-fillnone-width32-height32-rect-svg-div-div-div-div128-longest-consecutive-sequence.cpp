class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            if (nums.empty()) return 0;
            int n = nums.size();
            if (n == 1) return 1;

            map<int, bool> memo;
            int count = 0;
            int temp = 1;

            for (int x: nums)
            {
                memo[x] = false;
            }
            nums.clear();
            for (auto x: memo)
            {
                nums.push_back(x.first);
            }

            for (auto x: nums)
            {
                if (!memo[x])
                {
                    while (memo.find(x + 1) != memo.end())
                    {
                        temp++;
                        x++;
                        memo[x] = true;
                    }
                    count = max(count, temp);
                    temp = 1;
                }
            }

            return count;
        }
};