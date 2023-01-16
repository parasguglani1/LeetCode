class Solution
{
    public:
        int hammingWeight(uint32_t n)
        {
            int ans = 0;
            while (n > 0)
            {
                // cout<<n<<endl;
                
                ans += n % 2;
                n /= 2;
            }
            return ans;
        }
};