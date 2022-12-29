class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         int n=nums.size();
        sort(nums.begin(),nums.end());
           vector<vector<int>> ans;
        set<vector<int>>st;
//            for(auto x: nums)
//         {
//                cout<<x<<" ";
            
//         }
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                
            int left=j+1;
            int right =n-1;
            while(left<right)
            {
                long long curr=nums[left]+nums[right];
                curr+=nums[i]+nums[j];
                if(curr==target)
                {
                    vector<int> a={nums[i],nums[j],nums[left],nums[right]};
                    st.insert(a);
                    left++;
                }
                else if(curr<target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
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