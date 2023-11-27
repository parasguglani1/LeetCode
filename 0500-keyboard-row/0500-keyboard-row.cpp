class Solution {
public:
    bool canBeTyped(string str,string check)
    {
        
        map<char,int> mp;
        for(auto c:str)
        {
            if(c<'a')
            {
                c+=32;
            }
            mp[c]++;
        }
        for(auto c:check)
        {
             if(c<'a')
            {
                c+=32;
            }
            if(mp[c]==0)
            {
                return false;
            }
        }
        return true;
    }
    
    vector<string> findWords(vector<string>& words) {
        int n=words.size();
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            auto check=words[i];
            
            if(canBeTyped("qwertyuiop",check)||canBeTyped("asdfghjkl",check)||canBeTyped("zxcvbnm",check))
            {
                ans.push_back(check);
                
            }
            
        }
        return ans;
    }
};