class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int curr=columnTitle[i]-'A';
            ans=ans*26+curr+1;
        }
        return ans;
    }
};