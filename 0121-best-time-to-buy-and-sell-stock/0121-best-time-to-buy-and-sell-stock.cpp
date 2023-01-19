class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX;
        int maxprofit=0;
        for(auto x: prices)
        {
            if(mn>x)
            {
                mn=x;
            }
            else {
                maxprofit=max(maxprofit,x-mn);
            }
        }
        
        return maxprofit;
    }
};