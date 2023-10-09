class Solution
{
    public:
        void rotate(vector<int> &nums, int k)
        {
            int n = nums.size();

            k %= n;
                        
            //whole
            reverse(nums.begin(),nums.end());
            //first k
            reverse(nums.begin(),nums.begin()+k);
                
            //last k
            reverse(nums.begin()+k,nums.end());
                

        }
};