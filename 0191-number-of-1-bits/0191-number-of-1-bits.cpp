class Solution
{
    public:
        int hammingWeight(uint32_t n)
        {
            int ans = 0;
            while (n > 0)
            {
                // cout<<n<<endl;
                
                ans += n & 1;
                n >>=1;
            }
            return ans;
        }
};