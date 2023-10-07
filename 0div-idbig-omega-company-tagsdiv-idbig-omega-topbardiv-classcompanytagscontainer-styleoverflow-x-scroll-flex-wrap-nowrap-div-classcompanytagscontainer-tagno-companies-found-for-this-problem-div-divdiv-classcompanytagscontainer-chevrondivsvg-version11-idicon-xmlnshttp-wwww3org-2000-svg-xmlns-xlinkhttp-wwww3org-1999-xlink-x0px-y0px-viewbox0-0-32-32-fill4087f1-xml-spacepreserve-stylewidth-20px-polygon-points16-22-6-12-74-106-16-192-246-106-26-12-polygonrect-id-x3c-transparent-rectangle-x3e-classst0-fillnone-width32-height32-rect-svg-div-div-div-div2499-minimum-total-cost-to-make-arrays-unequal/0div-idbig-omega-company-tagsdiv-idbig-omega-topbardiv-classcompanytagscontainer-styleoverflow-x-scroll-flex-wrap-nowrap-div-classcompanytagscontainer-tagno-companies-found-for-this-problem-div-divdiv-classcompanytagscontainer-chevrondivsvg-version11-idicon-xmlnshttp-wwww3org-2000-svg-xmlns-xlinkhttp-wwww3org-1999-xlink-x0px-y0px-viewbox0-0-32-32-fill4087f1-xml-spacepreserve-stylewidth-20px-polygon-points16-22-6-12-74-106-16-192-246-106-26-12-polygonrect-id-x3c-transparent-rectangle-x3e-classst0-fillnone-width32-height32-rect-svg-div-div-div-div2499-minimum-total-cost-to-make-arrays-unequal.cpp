class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<bool>arr(n);//record pairs to change
        vector<int>pairs(n+1);//record frequency of pairs of number
        
        int cnt = 0;//number of pairs to change
        //build cnt and pairs
        for(int i = 0; i < n; i++){
            if(nums1[i] == nums2[i]){
                arr[i] = true;
                ++cnt;
                ++pairs[nums1[i]];
            }
        }

        //find the most frequent paired number x and its frequency y
        int x = -1, y = 0;
        for(int i = 1; i <= n; i++){
            if(pairs[i] > y){
                y = pairs[i];
                x = i;
            }
        }
        if(x == -1)return 0;

        //for index i, add it into pairs to change if it doesn't have any x
        int id = -1;
        while(2*y > cnt){
            ++id;
            if(id == n)return -1;//x is so much that we can't fill it in the whole array
            if(arr[id])continue;
            if(nums1[id] == x || nums2[id] == x)continue;
            ++cnt;
            arr[id] = true;
        }

        //since we have found all pairs to change, we could simply add up all the indices
        long long ret = 0;
        for(int i = 0; i < n; i++)if(arr[i])ret += i;
        return ret;
    }
};
