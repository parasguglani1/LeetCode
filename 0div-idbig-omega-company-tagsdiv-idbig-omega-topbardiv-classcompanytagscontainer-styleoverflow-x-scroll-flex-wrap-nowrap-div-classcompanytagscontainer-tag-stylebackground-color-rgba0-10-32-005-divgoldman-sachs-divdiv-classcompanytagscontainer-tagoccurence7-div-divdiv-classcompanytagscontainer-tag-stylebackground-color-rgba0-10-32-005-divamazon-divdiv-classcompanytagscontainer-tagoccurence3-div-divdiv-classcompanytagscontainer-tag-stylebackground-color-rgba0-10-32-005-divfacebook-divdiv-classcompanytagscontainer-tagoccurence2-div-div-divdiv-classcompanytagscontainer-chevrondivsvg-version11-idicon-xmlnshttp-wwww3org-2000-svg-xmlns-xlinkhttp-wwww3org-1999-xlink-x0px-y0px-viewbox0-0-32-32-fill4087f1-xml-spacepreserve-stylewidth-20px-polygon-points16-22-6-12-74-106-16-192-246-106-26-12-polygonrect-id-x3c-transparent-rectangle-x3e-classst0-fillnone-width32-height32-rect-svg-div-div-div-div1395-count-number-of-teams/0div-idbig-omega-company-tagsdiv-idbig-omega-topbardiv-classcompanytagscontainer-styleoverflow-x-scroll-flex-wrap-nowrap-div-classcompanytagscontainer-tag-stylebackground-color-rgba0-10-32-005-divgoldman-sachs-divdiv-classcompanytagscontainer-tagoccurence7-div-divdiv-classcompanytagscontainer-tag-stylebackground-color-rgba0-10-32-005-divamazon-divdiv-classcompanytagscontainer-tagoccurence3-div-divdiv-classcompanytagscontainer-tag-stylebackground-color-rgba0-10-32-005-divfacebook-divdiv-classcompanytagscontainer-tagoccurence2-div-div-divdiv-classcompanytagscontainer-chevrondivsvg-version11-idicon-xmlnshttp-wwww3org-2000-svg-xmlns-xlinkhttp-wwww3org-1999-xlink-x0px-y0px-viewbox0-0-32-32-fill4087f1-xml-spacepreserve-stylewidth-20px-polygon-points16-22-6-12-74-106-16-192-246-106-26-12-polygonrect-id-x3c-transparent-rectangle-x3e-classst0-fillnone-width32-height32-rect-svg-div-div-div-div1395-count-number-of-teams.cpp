class Solution {
public:
    int numTeams(vector<int>& rating) {
        //brute force
        int ans=0;
        int n=rating.size();
        for(int i=1;i<n-1;i++)
        {
            int lessThanBefore=0,lessThanAfter=0;
            
            for(int j=0;j<i;j++)
            {
                if(rating[j]<rating[i])
                {
                   lessThanBefore++; 
                }
            }
            for(int j=i+1;j<n;j++)
            {
               
                if(rating[j]<rating[i])
                {
                   lessThanAfter++; 
                } 
            }
            
            int moreThanBefore=i-lessThanBefore;
            int moreThanAfter=n-i-1-lessThanAfter;
            
            ans+=lessThanBefore*moreThanAfter;
            ans+=moreThanBefore*lessThanAfter;
        }
        return ans;
    }
};