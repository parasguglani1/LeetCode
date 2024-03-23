class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,vector<int>>mp;
        int ans=INT_MAX;
        int mxsize=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
            mxsize=max(mxsize,(int)mp[nums[i]].size());
        }
        // cout<<mxsize<<endl;
        for(auto x:mp)
        {
            int vsize=x.second.size();
            if(vsize==mxsize)
            {
            ans=min(ans,x.second[x.second.size()-1]-x.second[0]);
                
            }
        }
        return ans+1;
    }
};