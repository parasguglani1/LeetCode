class Solution {
public:
    string reverseWords(string s) {
        int  n=s.size();
        stringstream ss(s);
        string word;
        string ans="";
        while(ss>>word)
        {
            reverse(word.begin(),word.end());
            ans+=word+" ";
            
        }
        ans.pop_back();
        return ans;
        
    }
};