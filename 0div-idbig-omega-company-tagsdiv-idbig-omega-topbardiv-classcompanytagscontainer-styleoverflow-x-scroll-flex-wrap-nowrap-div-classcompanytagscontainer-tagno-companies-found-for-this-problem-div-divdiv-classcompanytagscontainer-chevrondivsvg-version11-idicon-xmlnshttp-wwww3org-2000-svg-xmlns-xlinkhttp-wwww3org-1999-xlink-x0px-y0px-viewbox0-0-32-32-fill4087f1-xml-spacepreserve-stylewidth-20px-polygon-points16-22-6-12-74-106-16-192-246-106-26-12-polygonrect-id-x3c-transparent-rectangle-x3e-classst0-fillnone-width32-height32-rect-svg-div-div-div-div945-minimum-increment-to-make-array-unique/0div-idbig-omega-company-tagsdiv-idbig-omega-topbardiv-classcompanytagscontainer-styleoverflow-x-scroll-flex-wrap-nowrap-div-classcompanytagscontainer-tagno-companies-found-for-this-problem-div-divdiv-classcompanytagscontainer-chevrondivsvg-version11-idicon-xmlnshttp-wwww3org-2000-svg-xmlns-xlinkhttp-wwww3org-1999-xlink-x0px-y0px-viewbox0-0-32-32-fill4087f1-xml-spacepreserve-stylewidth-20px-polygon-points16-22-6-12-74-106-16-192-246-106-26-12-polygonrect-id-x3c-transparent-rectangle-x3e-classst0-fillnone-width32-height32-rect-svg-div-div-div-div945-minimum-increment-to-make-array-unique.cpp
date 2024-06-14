class Solution
{
    public:
        int minIncrementForUnique(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int curr = nums[0];
            int ans = 0;
            for (int i = 1; i < n; i++)
            {
                int get = curr + 1;
                int have = nums[i];
                // cout<<get<<" "<<have<<" ";
                ans += max(get - have,0);
                curr=max(curr+1,nums[i]);
                // cout << i << " " << ans << endl;
            }
            return ans;
        }
};

// 1 1 2 2 3 7