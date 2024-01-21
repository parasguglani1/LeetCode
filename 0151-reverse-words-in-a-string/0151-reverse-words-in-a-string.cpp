class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> strs;
        string ans="",word;
        while(ss>>word)
        {
            strs.push_back(word);    
        }
        
        reverse(strs.begin(),strs.end());
        
        
        for(auto x:strs)
        {
            ans+=x;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
        
    }
};