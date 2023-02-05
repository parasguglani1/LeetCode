class Solution {
public:

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    int mid;
    // first element would always be on even index on left side and odd on right side
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        // int firstindex = mid, lastindex = mid;
        int firstindex = lower_bound(nums.begin(), nums.end(), nums[mid]) - nums.begin();
        int lastindex = upper_bound(nums.begin(), nums.end(), nums[mid]) - nums.begin() - 1;
        // if (firstindex > 0 && nums[firstindex] == nums[firstindex - 1])
        // {
        //     firstindex--;
        // }
        // if (lastindex < n - 1 && nums[lastindex] == nums[lastindex + 1])
        // {
        //     lastindex++;
        // }
        if ((lastindex - firstindex) % 2 == 0)
        {
            return nums[firstindex];
        }
        if (firstindex % 2 == 0)
        {
            start = lastindex + 1;
        }
        else
        {
            end = firstindex - 1;
        }
    }
    return nums[start];
}
};