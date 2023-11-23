class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n=l.size();
        vector<bool> ans(n);
        for(int i=0;i<n;i++)
        {
            int left=l[i],right=r[i];
            vector<int> temp;
            for(int j=left;j<=right;j++)
            {
                temp.push_back(nums[j]);
                
            }
            sort(temp.begin(),temp.end());
            
            int diff=0;
            if(temp.size()>1)
            {
                diff=temp[1]-temp[0];
            }
            bool flag=true;
            for(int j=1;j<temp.size();j++)
            {
                if(temp[j]-temp[j-1]!=diff)
                {
                    flag=false;
                }
            }
            ans[i]=flag;
        
        }   
        return ans;
        
    }
};