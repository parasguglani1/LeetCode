class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='a'|| c=='e'||c=='i'||c=='o'||c=='u')
        {
            return true;
        }
        if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
            {
                if(i>=s.size()/2)
                {
                    cnt--;
                }
                else
                {
                    cnt++;
                }
            }
            
        }
        return cnt==0;
    }
};