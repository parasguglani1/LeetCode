class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int judge=1;
        map<int,int> mp;
        
        for(auto x: trust)
        {
            mp[x[1]]++;
            
        }
        int mx=0;
        for(auto x: mp)
        {
            if(x.second>mx)
            {
                mx=x.second;
                judge=x.first;
            }
        }
             
        for(auto x: trust)
        {
            if(x[0]==judge)
            {
                return -1;
                
            }
        }
        if(mx!=n-1)
        {
            return -1;
        }
        
        
        return judge;
    }
};