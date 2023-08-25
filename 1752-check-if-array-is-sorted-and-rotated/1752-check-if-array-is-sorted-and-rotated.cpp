class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if((nums[(i+1)%n]<nums[i]))
                     cnt++;
        }
        return cnt<2;
    }
};