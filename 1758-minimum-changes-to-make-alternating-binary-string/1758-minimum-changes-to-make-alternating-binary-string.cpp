class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                cnt++;
                s[i]='1'-s[i]+'0';
            }
        }
        // cout<<s<<endl;
        return min(cnt,n-cnt);
    }
};