
class Solution {
public:

    int minPatches(vector<int>& nums, int n) {
#define ll long long int
        
        int ans=0;
        ll cursum=1;
        
        int sz=nums.size();
        int i=0;
        while(cursum<=n)
        {
            if(i<sz &&cursum>=nums[i])
            {
                cursum+=nums[i];
                i++;
            }
            else
            {
                cursum+=cursum;
                ans++;
            }
        }
        return ans;
    }
};