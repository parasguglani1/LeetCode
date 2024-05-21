class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> &temp, int i,vector<int> nums)
    {
        if(i==nums.size())
        {
            // cout<<i<<endl;
            ans.push_back(temp);
            return;
        }
        helper(ans,temp,i+1,nums);
        temp.push_back(nums[i]);
        helper(ans,temp,i+1,nums);
        temp.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        helper(ans,temp,0,nums);
            return ans;
    }
};