class Solution {
public:
    const int mod= 1e9+7;
    #define ll long long
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
       for(auto x:nums)
       {
           int temp=x;
           string s=to_string(x);
           reverse(s.begin(),s.end());
           int reversenum=stoi(s);
           temp=x-reversenum;
           mp[temp]++;
       }
        ll ans=0;
        
        for(auto x:mp)
        {
            ll freq=x.second;
            
            ll curfreq=(freq*(freq-1))/2;
            curfreq%=mod;
            ans+=curfreq;
            ans%=mod;
            
        }
        return ans;
    }
};