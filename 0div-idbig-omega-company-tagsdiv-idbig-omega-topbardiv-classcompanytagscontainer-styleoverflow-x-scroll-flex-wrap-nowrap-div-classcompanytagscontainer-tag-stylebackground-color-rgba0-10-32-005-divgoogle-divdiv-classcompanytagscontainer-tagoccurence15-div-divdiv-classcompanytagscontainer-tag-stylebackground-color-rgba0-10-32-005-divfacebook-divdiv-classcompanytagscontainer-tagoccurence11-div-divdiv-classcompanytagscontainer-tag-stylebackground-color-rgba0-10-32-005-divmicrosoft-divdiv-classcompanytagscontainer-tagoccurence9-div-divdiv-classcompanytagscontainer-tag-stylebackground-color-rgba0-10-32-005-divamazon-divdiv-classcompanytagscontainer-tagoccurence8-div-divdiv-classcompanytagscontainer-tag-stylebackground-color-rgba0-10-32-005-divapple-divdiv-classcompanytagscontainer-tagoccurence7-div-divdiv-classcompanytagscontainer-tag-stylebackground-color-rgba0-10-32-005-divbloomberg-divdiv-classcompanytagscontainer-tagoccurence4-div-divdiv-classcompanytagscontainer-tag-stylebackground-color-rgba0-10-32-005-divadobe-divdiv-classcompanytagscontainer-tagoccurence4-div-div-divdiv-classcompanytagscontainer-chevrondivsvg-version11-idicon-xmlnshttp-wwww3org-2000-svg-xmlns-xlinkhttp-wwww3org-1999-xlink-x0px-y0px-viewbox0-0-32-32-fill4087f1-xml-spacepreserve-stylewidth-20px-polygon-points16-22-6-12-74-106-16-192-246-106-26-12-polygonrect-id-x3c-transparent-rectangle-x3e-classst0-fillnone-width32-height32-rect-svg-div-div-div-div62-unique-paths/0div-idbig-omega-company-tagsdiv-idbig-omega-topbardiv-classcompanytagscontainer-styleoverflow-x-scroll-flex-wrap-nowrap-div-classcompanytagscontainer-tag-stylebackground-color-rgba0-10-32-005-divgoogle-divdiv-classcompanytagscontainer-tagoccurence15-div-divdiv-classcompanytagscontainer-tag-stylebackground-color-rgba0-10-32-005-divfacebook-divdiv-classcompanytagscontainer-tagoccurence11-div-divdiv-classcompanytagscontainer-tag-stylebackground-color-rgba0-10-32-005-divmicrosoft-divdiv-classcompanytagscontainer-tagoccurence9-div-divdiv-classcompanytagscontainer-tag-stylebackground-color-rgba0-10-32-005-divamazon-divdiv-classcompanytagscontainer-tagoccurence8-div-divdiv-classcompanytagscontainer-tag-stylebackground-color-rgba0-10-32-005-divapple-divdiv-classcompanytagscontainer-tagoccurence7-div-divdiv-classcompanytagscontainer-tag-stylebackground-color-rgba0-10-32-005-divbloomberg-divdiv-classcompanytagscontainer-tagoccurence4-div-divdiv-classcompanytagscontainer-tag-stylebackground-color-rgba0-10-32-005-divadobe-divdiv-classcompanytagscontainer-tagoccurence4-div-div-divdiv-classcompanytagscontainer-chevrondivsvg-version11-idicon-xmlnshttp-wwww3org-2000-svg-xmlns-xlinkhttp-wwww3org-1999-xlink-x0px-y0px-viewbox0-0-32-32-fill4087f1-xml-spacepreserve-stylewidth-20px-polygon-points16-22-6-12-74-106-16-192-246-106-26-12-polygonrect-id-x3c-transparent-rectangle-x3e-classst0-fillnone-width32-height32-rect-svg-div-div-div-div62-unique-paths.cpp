class Solution {
public:
    int uniquePaths(int m, int n) {
        // (m+n-2)!/(m-1)!(n-1)!
        if(m<n)
        {
            swap(m,n);
        }
//4 6 
        // 8!/5! 3!
            long long ans=1;
            for(int i=m,j=1;i<=m+n-2;i++,j++)
            {
                ans*=i;
                ans/=j;
            }
        // cout<<ans<<endl;
        // for(int i=1;i<n;i++)
        // {
        //     ans/=i;
        // }
        return ans;
    }
};