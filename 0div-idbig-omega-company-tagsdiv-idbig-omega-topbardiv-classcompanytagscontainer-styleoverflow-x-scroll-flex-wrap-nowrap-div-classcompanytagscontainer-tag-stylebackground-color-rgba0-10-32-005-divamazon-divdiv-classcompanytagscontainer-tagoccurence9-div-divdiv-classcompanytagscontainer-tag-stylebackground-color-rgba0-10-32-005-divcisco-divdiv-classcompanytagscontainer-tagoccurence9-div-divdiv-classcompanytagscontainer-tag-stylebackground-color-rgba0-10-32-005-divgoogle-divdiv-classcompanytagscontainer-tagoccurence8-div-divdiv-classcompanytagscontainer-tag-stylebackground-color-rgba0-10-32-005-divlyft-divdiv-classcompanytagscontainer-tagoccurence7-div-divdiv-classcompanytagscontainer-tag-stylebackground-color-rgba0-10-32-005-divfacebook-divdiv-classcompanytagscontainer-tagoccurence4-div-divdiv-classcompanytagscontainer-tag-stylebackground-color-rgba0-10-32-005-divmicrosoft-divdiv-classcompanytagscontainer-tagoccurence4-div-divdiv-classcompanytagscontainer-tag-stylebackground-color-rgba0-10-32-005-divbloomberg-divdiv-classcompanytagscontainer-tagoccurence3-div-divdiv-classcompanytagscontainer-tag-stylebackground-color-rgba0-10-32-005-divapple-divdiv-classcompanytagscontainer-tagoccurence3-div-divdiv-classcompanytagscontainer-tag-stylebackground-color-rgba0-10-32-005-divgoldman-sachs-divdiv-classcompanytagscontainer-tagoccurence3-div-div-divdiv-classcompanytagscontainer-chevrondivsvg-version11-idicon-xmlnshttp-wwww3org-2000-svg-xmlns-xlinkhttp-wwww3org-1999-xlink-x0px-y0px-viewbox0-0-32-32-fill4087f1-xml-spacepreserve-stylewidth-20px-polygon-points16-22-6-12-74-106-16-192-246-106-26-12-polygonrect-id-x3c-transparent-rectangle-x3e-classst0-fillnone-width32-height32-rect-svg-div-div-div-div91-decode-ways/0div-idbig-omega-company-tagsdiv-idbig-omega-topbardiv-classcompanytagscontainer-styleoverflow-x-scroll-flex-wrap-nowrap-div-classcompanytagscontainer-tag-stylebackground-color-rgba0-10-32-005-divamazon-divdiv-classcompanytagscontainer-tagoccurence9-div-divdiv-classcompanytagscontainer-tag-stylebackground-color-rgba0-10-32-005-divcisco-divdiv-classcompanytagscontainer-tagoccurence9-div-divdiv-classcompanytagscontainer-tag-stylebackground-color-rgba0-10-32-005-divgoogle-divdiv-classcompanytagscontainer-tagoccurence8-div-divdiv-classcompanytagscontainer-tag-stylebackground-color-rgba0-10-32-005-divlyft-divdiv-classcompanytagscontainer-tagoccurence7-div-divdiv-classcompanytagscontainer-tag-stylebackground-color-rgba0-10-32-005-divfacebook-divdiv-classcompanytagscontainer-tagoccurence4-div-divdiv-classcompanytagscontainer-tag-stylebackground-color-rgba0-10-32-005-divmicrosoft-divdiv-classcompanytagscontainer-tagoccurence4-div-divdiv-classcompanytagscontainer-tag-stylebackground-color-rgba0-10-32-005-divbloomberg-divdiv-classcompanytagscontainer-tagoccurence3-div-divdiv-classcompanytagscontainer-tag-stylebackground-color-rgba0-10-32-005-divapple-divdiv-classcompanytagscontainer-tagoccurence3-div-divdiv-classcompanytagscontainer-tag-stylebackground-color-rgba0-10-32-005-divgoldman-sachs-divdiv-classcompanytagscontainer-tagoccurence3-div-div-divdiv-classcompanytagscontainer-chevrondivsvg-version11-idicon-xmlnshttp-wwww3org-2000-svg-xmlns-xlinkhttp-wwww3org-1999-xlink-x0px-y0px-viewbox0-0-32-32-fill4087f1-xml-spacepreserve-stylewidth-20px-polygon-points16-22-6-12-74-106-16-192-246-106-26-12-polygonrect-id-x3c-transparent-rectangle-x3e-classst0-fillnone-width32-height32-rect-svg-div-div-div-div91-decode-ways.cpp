class Solution {
public:
    //memo
//     int getans(string &s, int ind,vector<int> &dp)
//     {
//         int n=s.size();
//         if(ind==n)
//         {
//             return 1;
//         }
//         if(s[ind]=='0')
//         {
//             return 0;
//         }
        
//         if(dp[ind]!=-1)
//         {
//             return dp[ind];
//         }
//         int takeonechar=getans(s,ind+1,dp);
        
        
//         int taketwochar=0;
        
//         if(ind+1<n &&(s[ind]=='1' || s[ind]=='2' && s[ind+1]<'7'))
//         {
//             taketwochar=getans(s,ind+2,dp);
//         }
        
//         return dp[ind]=taketwochar+takeonechar;  
        
//     }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[n]=1;
        //tab
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                dp[i]=0;
                continue;
            }
            dp[i]=dp[i+1];
            if(i+1<n && (s[i]=='1' ||(s[i]=='2' && s[i+1]<'7')))
            {
                dp[i]+=dp[i+2];
            }
            
        }
        return dp[0];
        

        // return getans(s,0,dp);
    }
};