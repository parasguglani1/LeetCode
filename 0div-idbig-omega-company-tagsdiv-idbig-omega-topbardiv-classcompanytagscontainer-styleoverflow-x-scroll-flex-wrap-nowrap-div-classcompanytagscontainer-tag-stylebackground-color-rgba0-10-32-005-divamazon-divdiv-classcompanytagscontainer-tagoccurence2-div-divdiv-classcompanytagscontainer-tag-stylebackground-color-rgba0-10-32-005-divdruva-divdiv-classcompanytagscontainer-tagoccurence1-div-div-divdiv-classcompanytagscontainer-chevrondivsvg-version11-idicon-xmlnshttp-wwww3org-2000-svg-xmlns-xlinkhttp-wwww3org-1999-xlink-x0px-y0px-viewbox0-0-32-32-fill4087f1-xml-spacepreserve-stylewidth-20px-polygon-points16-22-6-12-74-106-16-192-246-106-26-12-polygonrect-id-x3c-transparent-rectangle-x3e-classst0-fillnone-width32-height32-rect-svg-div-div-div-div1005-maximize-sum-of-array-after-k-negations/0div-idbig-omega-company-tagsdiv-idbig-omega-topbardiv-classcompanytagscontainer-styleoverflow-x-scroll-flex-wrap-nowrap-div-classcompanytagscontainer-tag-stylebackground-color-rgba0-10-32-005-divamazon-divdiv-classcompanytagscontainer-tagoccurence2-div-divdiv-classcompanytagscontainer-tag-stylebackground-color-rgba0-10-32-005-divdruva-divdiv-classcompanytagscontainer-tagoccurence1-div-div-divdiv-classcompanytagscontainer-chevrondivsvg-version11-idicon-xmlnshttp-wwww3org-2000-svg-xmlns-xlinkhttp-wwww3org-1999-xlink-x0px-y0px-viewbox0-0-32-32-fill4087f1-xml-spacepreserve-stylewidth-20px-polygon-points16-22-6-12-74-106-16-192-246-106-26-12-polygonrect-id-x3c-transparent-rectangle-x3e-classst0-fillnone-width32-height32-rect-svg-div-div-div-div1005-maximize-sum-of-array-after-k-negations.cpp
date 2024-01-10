class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
    
    priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x:nums)
        {
            pq.push(x);
            
        }
        
        while(k>0)
        {
            int x=pq.top();
            x*=-1;
            pq.pop();
            pq.push(x);
            k--;
        }
        int sm=0;
        while(pq.empty()==false)
        {
            sm+=pq.top(),pq.pop();
        }
        return sm;
    }
};