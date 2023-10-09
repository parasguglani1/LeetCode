class Solution
{
    public:
        void rotate(vector<int> &nums, int k)
        {
            int n = nums.size();

            k %= n;
            valarray<int> v(nums.data(), n);
            
            // valarray v(n);
            // for(int i=0;i<n;i++)
            // {
            //     v[i]=nums[i];
            // }

            v = v.cshift(-k);

            nums.assign(begin(v), end(v));
        }
};