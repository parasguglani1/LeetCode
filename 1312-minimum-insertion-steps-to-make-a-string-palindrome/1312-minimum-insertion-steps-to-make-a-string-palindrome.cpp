class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        string S1=s;
        string S2=s;
        reverse(S2.begin(),S2.end());
        vector<int> prev(n+1,0);
        vector<int> next(n+1,0);
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(S1[i-1]==S2[j-1])
                    next[j]=1+prev[j-1];
                else
                    next[j]=max(prev[j],next[j-1]);
            }
            prev=next;
        }
        return n-next[n];
    }
};
