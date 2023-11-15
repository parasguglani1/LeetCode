class Solution
{
    public:
//recursive
        int getways(int ind, int target, vector<int> &nums)
        {

            if (ind == 0)
            {
                if (target == 0 &&nums[0]==0)
                {
                    return 2;
                    
                }
                if (target == nums[0]||target==0)
                {
                    return 1;
                }
                return 0;
            }
            int take = 0, nottake = 0;
            if (target >= nums[ind])
                take = getways(ind - 1, target - nums[ind], nums);
            nottake = getways(ind - 1, target, nums);
            return take + nottake;
        }
    int findTargetSumWays(vector<int> &nums, int target)
    {
       	// sum1+sum2=totalsum
       	// sum1-sum2=target;
       	// 2 *sum1 =totalsum+target

       	// sum1=totalsum-sum2;
       	// totalsum-2 *subsetsum =target;
       	// subsetsum=(totalsum-target)/2;

       	// i.e find no of ways to make this subset sum
        int n = nums.size();
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        int subsetsum = totalsum - target;
        if (subsetsum % 2)
        {
            return false;
        }
        subsetsum /= 2;

        int ans = getways(n - 1, subsetsum, nums);
        return ans;
    }
};