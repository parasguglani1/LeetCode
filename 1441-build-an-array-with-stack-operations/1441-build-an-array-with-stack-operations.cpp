class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int sz=target.size();
        vector<int> freq(n+1,0);
        int cnt=sz;
        for(int i=0;i<sz;i++)
        {
            freq[target[i]]++;
        }
        
        vector<string> ans;
        for(int i=1;i<=n;i++)
        {
        ans.push_back("Push");

            if(freq[i])
            {
                cnt--;
                if(cnt==0)
                {
                    return ans;
                }
            }
            else
            {
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};