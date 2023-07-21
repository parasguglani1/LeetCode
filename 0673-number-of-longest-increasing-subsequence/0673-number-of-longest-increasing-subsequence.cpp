class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();
        if(n==0) return 0;
        
        // DP list tracks the LIS of nums from start to ith index
        // Every value in nums has LIS 1
        vector<int>dp(n,1);
        
        // Stores the count of the number of LIS of nums from start to ith index
        // Every value in nums has LIS 1 and they have at least 1 combination of LIS 
        vector<int>count(n,1);
        
         // Max LIS length
        int maxL = 1;
        
        // Final result of number of max LIS
        int res = 0;
        
        int current = 0;
        
        // Loop through the elements starting from second element
        for(int i=1;i<nums.size();i++)
        {
            // Stores the LIS length till ith index in DP which statisfies below conditions
            current = 0;
            
            // Compare all values from start till the current index
            for(int j=0;j<i;j++)
            {
                // Check if the jth index value is less than the current index value cause it satisfies the
                // condition for IS and if so then check whether the jth index LIS value is greater than 
                // or equal current LIS value, if yes then update current LIS with dp[j] cause we want to get the maxLength LIS
                
                // If above condition satisfied, we also update count[i] with count[j] if dp[j] > current 
                // cause we got larger LIS value so we need to update the number of LIS of 
                // jth index to ith index which is count[i] = count[j];
                // Otherwise we add count[j] with count[i] because we found another LIS equal to current LIS
                // which can generate another combination of max LIS till ith index
                
                if(nums[j]<nums[i] && dp[j] >= current)
                {
                    if(dp[j]==current)count[i]+=count[j];
                    else count[i] = count[j];
                    current = dp[j];                    
                }                
            }
                     
            // We add 1 with current cause current holds the LIS till the current index and as 
            // current index is included we add 1 with it 
            dp[i] = current + 1;
            maxL = max(maxL,dp[i]);
        }
        

        // We go through the dp list and check ith index which has value of max LIS 
        // and we add their number of LIS of ith index from count list with the result
        for(int i=0;i<nums.size();i++)
            if(dp[i]==maxL)res+=count[i];            

        return res;
        
    }
    
};
