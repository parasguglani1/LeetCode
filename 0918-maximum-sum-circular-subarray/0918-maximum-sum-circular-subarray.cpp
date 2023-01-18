class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n=nums.size();
//         int prefixsum=0,maxprefix=nums[0];
      
//         int i=0;
// //         while(prefixsum>=0 &&i<n)
// //         {
// //             prefixsum+=nums[i];
            
// //             maxprefix=max(maxprefix,prefixsum);
// //             i++;
        
// //         }
//         int kadanesum=0,maxkadanesum=nums[0];
//         for(int i=0;i<n;i++)
//         {
//             kadanesum+=nums[i];
            
//             maxkadanesum=max(maxkadanesum,kadanesum);
//             if(kadanesum<0)
//             {
//                 kadanesum=0;
//             }
            
//         }
        
//            int suffixsum=0,maxsuffix=nums[n-1];
//          i=n-1;
// //         while(suffixsum>=0 &&i>-1)
// //         {
// //             suffixsum+=nums[i];
            
// //             maxsuffix=max(maxsuffix,suffixsum);
// //             i--;
        
// //         }
//         // return 1;
//         int sum=0;
//         for(int i=0;i<n;i++)
//         {
            
            
//         }
//         int maxpresuf=nums[0];
//         for(int i=0;i<n;i++)
//         {
            
            
//         }
        
//         return max({maxsuffix,maxprefix,maxkadanesum,maxprefix+maxsuffix});
        
        
        int totalSum = 0, maxSum = INT_MIN, curMax = 0, minSum = INT_MAX, curMin = 0;
    for (int x : nums) {
        curMax = max(x, curMax + x);  //update the current max subarray sum
        maxSum = max(maxSum, curMax); //update the overall max subarray sum
        curMin = min(x, curMin + x);  //update the current min subarray sum
        minSum = min(minSum, curMin); //update the overall min subarray sum
        totalSum += x;
    }
    return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;

        
    }
};