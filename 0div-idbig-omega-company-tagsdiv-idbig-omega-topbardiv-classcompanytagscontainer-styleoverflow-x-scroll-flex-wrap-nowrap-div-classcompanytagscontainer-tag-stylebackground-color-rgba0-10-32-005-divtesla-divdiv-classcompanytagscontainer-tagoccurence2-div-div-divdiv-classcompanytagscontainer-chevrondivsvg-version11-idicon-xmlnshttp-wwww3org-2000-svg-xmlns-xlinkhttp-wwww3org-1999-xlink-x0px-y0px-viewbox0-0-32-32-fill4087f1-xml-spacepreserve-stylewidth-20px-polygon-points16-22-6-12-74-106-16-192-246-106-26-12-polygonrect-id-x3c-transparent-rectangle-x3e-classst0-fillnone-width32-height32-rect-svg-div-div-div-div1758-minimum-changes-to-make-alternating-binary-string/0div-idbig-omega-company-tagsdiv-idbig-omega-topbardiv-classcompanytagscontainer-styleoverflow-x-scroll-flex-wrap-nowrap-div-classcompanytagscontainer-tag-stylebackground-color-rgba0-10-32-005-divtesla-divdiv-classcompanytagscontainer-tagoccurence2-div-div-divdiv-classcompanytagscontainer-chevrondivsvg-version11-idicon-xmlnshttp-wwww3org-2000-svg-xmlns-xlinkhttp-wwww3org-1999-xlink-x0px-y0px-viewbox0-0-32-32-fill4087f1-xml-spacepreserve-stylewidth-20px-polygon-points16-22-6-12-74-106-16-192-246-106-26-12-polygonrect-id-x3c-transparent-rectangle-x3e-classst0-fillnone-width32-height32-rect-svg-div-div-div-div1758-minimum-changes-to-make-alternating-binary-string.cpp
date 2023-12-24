class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        
        string str1(n,'1'),str2(n,'0');
        
        for(int i=1;i<n;i+=2)
        {
            str1[i]='0';
            str2[i]='1';
        }
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=str1[i])
            {
                cnt1++;
            }
            if(s[i]!=str2[i])
            {
                cnt2++;
            }
        }
        return min(cnt2,cnt1);
        // cout<<str1<<' '<<str2<<endl;;
    }
};