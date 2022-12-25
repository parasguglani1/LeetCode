class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
           vector<vector<int>> ans;
        set<vector<int>>st;
        for(int i=0;i<n-2;i++)
        {
            int target=-nums[i];
            int left=i+1;
            int right =n-1;
            while(left<right)
            {
                if(nums[left]+nums[right]==target)
                {
                    vector<int> a={nums[i],nums[left],nums[right]};
                    st.insert(a);
                    left++;
                }
                else if(nums[left]+nums[right]<target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        
        for(auto x: st)
        {
            ans.push_back(x);
            
        }
        return ans;
    }
};