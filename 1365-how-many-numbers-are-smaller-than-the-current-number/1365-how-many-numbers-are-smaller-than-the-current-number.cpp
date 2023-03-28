class Solution
{
    public:
        vector<int> smallerNumbersThanCurrent(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> ans(n),num(nums);
            // vector<pair<int, int>> num;
        
            sort(num.begin(), num.end());
            for (int i = 0; i < n; i++)
            {
                ans[i]=lower_bound(num.begin(),num.end(),nums[i])-num.begin();
            }
            return ans;
        }
};