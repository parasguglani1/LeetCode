class Solution {
public:
    string truncateSentence(string s, int k) {
       int count = 0;
       string ans = "";

       for(int i = 0; i < s.length(); i++) {
           if(s[i] == ' ') {
               count++;
               if(count == k) {
                   break;
               }
           }
           ans += s[i];
       } 

       while(ans.back() == ' ') {
           ans.pop_back();
       }

       return ans;
    }
};
