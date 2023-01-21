class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index=0;
        index=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        // cout<<index<<endl;
        if (index>=0 && index<nums.size()&&nums[index]==target)
        {
            return index;
            
        }
        return -1;
    }
};