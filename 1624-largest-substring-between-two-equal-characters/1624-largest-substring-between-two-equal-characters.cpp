class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
     int ans=-1;
        vector<int> freq(26,-1);
        for(int i=0;i<s.size();i++)
        {
            if(freq[s[i]-'a']!=-1)
            {
                ans=max(ans,i-freq[s[i]-'a']-1);
                
            }
            
            else
            {
                freq[s[i]-'a']=i;
            }
        }
        return ans;
    }
};