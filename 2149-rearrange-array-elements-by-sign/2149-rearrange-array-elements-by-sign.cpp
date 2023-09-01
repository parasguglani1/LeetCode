class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      int i=0,n=nums.size(),j=1;
                vector<int> ans(n, 0);

            for(auto num : nums){
            if(num > 0){
                ans[i] = num;
                i += 2;
            }
            else if(num < 0){
                ans[j] = num;
                j += 2;
            }
        }
        return ans;

    }
};