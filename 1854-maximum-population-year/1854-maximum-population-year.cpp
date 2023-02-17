class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int a[101]={0};
        for(auto x:logs)
        {
            a[x[0]-1950]++;
            a[x[1]-1950]--;
            
        }
        int mn=0,ans=0;
        int curr=0;
        for(int i=0;i<=100;i++)
        {
            curr+=a[i];
            if(curr>mn)
            {
                mn=curr;
                ans=i;
            }
            
        }
        return ans+1950;
    }
};