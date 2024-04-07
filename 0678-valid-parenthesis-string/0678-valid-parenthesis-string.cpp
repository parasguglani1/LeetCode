class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        stack<char> st;
        int open=0;
        int tot=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                // st.push('(');
                open++;
                tot++;
            }
            else if(s[i]==')')
            {
                open--;
                tot--;
            }
            else
            {
                open--;
                tot++;
            }
            open=max(open,0);
            if(tot<0)
            {
                return 0;
            }
        }
        return open==0;
    }
};