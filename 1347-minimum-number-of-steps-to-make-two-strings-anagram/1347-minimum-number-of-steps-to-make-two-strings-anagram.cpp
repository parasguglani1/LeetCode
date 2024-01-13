class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26,0),v2(26,0);
        // map<char,int> v,v2;
        for(auto x:t)
        {
            v[x-'a']++;
            
        }
        for(auto x:s)
        {
            v2[x-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            // cout<<x.first<<' '<<x.second<<endl;
            ans+=abs(v[i]-v2[i]);
            
            
            // if(x.second>mp[x.first])
            // {
            //     ans+=x.se
            // }
        }
        return ans/2;
        
    }
};