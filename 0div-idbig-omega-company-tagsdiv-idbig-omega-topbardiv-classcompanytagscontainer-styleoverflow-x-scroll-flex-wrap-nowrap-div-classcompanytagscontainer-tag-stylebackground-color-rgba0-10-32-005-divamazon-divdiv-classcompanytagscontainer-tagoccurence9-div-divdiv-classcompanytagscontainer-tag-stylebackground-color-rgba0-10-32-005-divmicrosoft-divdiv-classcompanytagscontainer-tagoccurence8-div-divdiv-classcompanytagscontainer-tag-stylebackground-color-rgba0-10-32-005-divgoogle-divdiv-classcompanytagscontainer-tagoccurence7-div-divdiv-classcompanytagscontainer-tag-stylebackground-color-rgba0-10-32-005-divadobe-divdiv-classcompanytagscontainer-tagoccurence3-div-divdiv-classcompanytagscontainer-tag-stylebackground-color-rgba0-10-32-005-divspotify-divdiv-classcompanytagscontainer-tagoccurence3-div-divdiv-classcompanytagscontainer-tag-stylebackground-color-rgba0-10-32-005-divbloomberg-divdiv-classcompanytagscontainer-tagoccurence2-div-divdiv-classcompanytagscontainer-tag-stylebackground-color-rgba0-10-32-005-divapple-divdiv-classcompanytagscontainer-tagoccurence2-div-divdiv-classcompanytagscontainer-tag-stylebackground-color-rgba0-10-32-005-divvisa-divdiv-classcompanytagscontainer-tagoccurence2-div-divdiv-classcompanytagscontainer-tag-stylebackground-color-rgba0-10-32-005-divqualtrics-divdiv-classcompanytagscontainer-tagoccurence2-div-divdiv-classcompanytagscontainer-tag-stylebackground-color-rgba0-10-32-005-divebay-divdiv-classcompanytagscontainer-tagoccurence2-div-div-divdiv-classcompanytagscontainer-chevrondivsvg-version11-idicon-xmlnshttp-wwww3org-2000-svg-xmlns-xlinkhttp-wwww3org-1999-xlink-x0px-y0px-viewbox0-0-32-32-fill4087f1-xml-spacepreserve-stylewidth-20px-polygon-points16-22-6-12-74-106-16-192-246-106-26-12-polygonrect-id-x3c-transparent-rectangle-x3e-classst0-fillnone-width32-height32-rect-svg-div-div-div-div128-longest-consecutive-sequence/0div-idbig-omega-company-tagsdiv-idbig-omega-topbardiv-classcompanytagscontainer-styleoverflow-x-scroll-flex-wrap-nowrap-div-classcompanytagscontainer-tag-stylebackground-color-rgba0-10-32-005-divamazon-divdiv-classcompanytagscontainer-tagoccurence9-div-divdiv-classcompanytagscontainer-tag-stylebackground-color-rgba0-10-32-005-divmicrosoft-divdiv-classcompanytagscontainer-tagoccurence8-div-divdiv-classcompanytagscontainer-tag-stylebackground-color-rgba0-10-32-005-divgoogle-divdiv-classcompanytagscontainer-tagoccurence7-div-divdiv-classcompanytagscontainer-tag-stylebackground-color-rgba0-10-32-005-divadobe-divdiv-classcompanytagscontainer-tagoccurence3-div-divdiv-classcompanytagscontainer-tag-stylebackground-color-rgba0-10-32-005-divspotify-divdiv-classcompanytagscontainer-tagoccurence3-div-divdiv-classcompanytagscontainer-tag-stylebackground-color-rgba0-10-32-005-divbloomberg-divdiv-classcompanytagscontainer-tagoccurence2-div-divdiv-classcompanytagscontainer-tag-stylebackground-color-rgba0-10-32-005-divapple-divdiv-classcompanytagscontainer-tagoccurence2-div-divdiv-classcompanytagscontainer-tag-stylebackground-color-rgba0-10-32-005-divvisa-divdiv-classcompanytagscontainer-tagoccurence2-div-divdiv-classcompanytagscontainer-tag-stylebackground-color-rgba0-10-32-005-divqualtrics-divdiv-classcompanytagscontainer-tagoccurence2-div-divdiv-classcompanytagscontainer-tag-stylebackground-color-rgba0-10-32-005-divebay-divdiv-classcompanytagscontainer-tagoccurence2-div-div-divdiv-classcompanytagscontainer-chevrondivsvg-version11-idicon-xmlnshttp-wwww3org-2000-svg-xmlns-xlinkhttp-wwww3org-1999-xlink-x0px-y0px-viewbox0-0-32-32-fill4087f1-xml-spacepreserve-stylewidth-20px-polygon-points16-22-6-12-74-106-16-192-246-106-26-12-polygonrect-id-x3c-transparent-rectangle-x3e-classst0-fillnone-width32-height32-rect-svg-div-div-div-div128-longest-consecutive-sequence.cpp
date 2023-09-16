class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st;
        for (int num : nums)
        {
            st.insert(num);
        }
        int ans = 0;

        for (int num : nums)
        {
            if (st.find(num) == st.end())
            {
                // Skip if the number has already been removed
                continue;
            }

            int cnt = 1;
            int curr = num;

            // Check and remove consecutive numbers smaller than the current number
            while (st.find(curr - 1) != st.end())
            {
                st.erase(curr - 1);
                curr--;
                cnt++;
            }

            curr = num;

            // Check and remove consecutive numbers larger than the current number
            while (st.find(curr + 1) != st.end())
            {
                st.erase(curr + 1);
                curr++;
                cnt++;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};
