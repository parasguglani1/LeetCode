
#define ll long long
class Solution
{
    public:
        long long minimumReplacement(vector<int> &nums)
        {
            ll ans = 0;
            ll n = nums.size();
            ll curmax = INT_MAX;
            for (int i = n - 1; i >= 0; --i)
            {
                ll k = (nums[i] + curmax - 1) / curmax;
                curmax = nums[i] / k;
                ans += k - 1;
            }
            return ans;
        }
};