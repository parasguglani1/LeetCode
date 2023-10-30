class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        if( n == 1) return 1;

        unordered_map<int, bool> memo;
        int count = 0;
        int temp = 1;

        for(int x : nums){
            memo[x] = false;
        }
      
        for(auto kv : memo){
            int x = kv.first;
            if(!memo[x]){
            while(memo.find(x+1) != memo.end()){
                temp++;
                x++;
                memo[x] = true;
            }
            count = max(count,temp);
            temp = 1;
            }


        }

        return count;

    }
};