class Solution
{
    public:
        int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
        {
            int initialScore = 0;
            int n = customers.size();
            for (int i = 0; i < n; i++)
            {
                if (!grumpy[i])
                    initialScore += customers[i];
            }
            
            int ans=initialScore;
            
            if(minutes>=n)
            {
                ans=accumulate(customers.begin(),customers.end(),0);
                return ans;
                
            }
            int ansChange=0;
            for(int i=0;i<minutes;i++)
            {
                if(grumpy[i])
                {
                    ansChange+=customers[i];
                }
            }
            int maxansChange=ansChange;
            
            for(int i=minutes;i<n;i++)
            {
                if(grumpy[i-minutes])
                {
                    ansChange-=customers[i-minutes];
                }
                if(grumpy[i])
                {
                    ansChange+=customers[i];
                }
                maxansChange=max(ansChange,maxansChange);
                
            }
            return ans+maxansChange;
                
        }
};