
#define mod 1000000007

class Solution
{

    public:
        int binpow(long long a, long long b)
        {
            int ans = 1;
            while (b > 0)
            {
                if (b & 1)
                    ans = ((ans % mod) *a) % mod;
                a = ((a % mod) *(a % mod)) % mod;
               	// b >>=  1;
                b = b >> 1;
            }
            return ans % mod;
        }
    int numSubseq(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;
        long long ans = 0;
        while (i <= j)
        {
            if (nums[i] + nums[j] <= target)
            {
                int diff = j - i + 1;
                long long curr = binpow(2, diff - 1);
                ans = (ans + curr)%mod;
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
};