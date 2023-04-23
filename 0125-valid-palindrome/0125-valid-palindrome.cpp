class Solution {
public:
    bool isPalindrome(string s) {
        
        
        int n=s.size();
        string s2="";
        for(int i=0;i<n;i++)
        {
            if(isalnum(s[i]))
            {
                s2+=tolower(s[i]);
            }
        }
        
         s=s2;
        
	    string t=s;
	    reverse(t.begin(),t.end());
	    return t==s;

    }
};