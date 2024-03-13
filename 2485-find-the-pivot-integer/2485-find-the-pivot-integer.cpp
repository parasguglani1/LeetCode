class Solution {
public:
    int pivotInteger(int n) {
    int sm=(n*(n+1))/2;
        int ans=sqrt(sm);
        // cout<<ans<<endl;
        if(ans*ans==sm)
        {
            return ans;
        }
        return -1;
    }
};