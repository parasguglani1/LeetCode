class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0 || n>=k+maxPts)return 1.0;

        vector<double>dp(n+1);
        dp[0]=1.0;

        double currsum=1.0;
        double ans=0.0;
        for(int i=1;i<n+1;i++){
            dp[i]=currsum/maxPts;
             if(i<k){
                 currsum += dp[i];
             }else ans+= dp[i];

             if(i>=maxPts){
                 currsum-= dp[i-maxPts];
             }
        }
        return ans;
    }
};
