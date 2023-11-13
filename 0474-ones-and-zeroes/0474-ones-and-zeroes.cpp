class Solution {
public:
    
   int getans(int ind,int m,int n,vector<string>& strs,vector<vector<vector<int>>>&dp)
    {
   
        //take
        
        string curstr=strs[ind];
        int sz=curstr.size();
        int cnt1=count(curstr.begin(),curstr.end(),'1');
        int cnt0=sz-cnt1;
        
        if(ind==0)
        {
            if(cnt1<=n &&cnt0<=m)
            {
                return 1;
            }
            return 0;
        } 
       if(dp[ind][m][n]!=-1)
       {
           return dp[ind][m][n];
       }
       int take=0;
       if(m>=cnt0 &&n>=cnt1)
        take=1+getans(ind-1,m-cnt0,n-cnt1,strs,dp);
        //nottake
        
        int nottake=getans(ind-1,m,n,strs,dp);
       if(ind<0 ||n<0||m<0)
       {
           cout<<"hi"<<endl;
       }
       
        int ans=0;
        return  dp[ind][m][n]= max(take,nottake);    
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();        
        vector<vector<vector<int>>>dp (sz,vector<vector<int>>(m+1,vector<int> (n+1,-1)));
        int ans=getans(sz-1,m,n,strs,dp);
        return ans;
    }
};