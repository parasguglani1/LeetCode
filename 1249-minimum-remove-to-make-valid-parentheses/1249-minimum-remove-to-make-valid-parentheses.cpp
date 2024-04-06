class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> open,close;
        int n=s.size();
        int openc=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                openc++;
                open.push_back(i);
            }
            else if(s[i]==')')
            {
                if(openc==0)
                {
                    s[i]='0';
                }
                else
                {
                    openc--;
                    open.pop_back();
                }
            }
        }
        for(auto i:open)
        {
            s[i]='0';
        }
        string ans="";
        for(auto x:s)
        {
            if(x!='0')
            {
                ans+=x;
            }
        }
        return ans;
    }
};