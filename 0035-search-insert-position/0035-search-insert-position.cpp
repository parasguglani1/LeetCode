class Solution
{
    public:
        int searchInsert(vector<int> &nums, int target)
        {
            // int l = 0;
            // int n = nums.size();
            // if (nums[n - 1] < target)
            // {
            //     return n;
            // }
            // if (nums[0] > target)
            // {
            //     return 0;
            // }
            // int r = n - 1;
            // while (l <= r)
            // {
            //     int mid = l + (r - l) / 2;
            //     if (nums[mid] == target)
            //     {
            //         return mid;
            //     }
            //     else if (nums[mid] < target)
            //     {
            //         r = mid-1 ;
            //     }
            //     else
            //     {
            //         l = mid + 1;
            //     }
            // }
            // return l;
            return (lower_bound(nums.begin(),nums.end(),target)-nums.begin());
        }
};