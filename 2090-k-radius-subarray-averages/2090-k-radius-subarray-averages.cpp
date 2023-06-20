class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n);
        long long sm=0;
        int i=0;
        while(i<n &&i<2*k)
        {
            ans[i]=-1;
            sm+=nums[i];
            i++;
        }
        cout<<sm<<endl;
        for(int j=k;j<n-k;j++)
        {
            sm+=nums[j+k];
            ans[j]=sm/(2*k+1);
            sm-=nums[j-k];
        }
        for(int j=n-k;j<n &&j>=0;j++)
        {
            ans[j]=-1;
        }
 return ans;
    }
};