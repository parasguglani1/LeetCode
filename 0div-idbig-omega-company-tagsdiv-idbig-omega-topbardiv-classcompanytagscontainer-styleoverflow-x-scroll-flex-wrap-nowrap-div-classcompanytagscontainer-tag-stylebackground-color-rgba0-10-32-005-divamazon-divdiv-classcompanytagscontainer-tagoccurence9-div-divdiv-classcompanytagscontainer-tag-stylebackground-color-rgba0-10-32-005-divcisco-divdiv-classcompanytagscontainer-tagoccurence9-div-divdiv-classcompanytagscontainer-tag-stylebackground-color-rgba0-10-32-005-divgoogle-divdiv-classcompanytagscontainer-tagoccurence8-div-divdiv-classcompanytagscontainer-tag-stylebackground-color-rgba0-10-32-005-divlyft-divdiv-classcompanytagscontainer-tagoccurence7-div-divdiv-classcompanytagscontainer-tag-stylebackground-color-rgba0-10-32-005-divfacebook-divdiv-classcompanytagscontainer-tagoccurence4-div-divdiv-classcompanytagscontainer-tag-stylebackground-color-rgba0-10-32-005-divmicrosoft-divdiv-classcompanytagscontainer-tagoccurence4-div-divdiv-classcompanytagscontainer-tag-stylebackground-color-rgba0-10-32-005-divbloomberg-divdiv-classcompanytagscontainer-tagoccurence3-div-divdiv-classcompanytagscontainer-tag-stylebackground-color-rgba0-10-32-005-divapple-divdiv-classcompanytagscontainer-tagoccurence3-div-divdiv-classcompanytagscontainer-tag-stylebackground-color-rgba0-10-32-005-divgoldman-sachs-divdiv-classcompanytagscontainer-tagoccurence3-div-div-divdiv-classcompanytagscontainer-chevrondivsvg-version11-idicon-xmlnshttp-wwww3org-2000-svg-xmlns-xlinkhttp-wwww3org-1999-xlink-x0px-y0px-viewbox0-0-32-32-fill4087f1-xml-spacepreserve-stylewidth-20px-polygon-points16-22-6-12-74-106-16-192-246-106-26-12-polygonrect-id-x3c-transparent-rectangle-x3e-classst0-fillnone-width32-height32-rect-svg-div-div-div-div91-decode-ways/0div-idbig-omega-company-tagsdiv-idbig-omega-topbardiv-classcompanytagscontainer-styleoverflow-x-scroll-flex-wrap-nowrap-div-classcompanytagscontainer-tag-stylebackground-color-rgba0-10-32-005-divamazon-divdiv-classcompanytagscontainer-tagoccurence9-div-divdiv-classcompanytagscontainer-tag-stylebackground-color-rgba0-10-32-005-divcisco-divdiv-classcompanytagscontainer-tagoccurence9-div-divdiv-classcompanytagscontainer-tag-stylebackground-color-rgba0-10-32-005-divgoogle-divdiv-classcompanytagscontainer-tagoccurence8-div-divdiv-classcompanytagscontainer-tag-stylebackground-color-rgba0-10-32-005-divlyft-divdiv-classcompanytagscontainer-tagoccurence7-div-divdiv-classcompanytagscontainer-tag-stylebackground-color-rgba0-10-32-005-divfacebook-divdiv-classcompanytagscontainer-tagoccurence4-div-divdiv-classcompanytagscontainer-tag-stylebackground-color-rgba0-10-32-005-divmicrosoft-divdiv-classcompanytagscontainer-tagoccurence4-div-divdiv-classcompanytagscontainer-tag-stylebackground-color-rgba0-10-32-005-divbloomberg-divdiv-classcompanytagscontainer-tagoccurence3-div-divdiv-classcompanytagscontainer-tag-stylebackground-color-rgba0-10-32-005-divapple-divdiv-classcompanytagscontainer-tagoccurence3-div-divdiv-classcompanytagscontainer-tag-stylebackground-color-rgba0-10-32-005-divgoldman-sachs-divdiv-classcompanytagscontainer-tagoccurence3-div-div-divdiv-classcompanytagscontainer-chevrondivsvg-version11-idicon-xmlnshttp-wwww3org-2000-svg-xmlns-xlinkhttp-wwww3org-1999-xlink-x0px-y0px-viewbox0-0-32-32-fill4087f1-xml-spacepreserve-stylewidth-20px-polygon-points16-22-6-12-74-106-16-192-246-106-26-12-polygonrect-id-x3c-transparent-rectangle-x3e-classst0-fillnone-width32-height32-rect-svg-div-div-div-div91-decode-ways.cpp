class Solution {
public:
    
    int getans(string &s, int ind,vector<int> &dp)
    {
        int n=s.size();
        if(ind==n)
        {
            return 1;
        }
        if(s[ind]=='0')
        {
            return 0;
        }
        
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int takeonechar=getans(s,ind+1,dp);
        
        
        int taketwochar=0;
        
        if(ind+1<n &&(s[ind]=='1' || s[ind]=='2' && s[ind+1]<'7'))
        {
            taketwochar=getans(s,ind+2,dp);
        }
        
        return dp[ind]=taketwochar+takeonechar;  
        
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
                dp[n]=1;

        return getans(s,0,dp);
    }
};