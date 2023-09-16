class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            set<int> s;
            int ans = 0;
            for (int x: nums)
            {
                s.insert(x);
            }
            for (int i = 0; i < nums.size(); i++)
            {
                int count = 0;
                int current_element = nums[i];	// if 2
                int previous_element = current_element - 1;	//then 1 
                if (s.find(previous_element) == s.end())
                {
                    while (s.find(current_element) != s.end())
                    {
                        current_element++;
                        count++;
                    }
                }
                ans = max(ans, count);
            }
            return ans;
        }
};