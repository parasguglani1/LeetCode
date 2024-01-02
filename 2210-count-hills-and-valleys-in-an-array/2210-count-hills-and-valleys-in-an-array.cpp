class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n-1;i++)
        {
            int leftnonequal=-1;
            int rightnonequal=-1;
            if(nums[i]==nums[i-1])
            {
                continue;
            }
            for(int j=i;i>=0;j--)
            {
                if(nums[j]!=nums[i])
                {
                    leftnonequal=nums[j];
                    break;
                }
            }
            for(int j=i;j<n;j++)
            {
                if(nums[j]!=nums[i])
                {
                    rightnonequal=nums[j];
                    break;
                }
            }
            
            if(rightnonequal!=-1 &&leftnonequal!=-1)
            {
                if((nums[i]>rightnonequal &&nums[i]>leftnonequal) || (nums[i]<rightnonequal &&nums[i]<leftnonequal))
                {
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
};