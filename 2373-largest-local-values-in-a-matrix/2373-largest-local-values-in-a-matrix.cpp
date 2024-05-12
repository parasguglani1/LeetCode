class Solution {
public:
    int getans(int r,int c, vector<vector<int>> & grid)
    {
        int ans=0;
        for(int i=r;i<r+3;i++)
        {
            for(int j=c;j<c+3;j++)
            {
                ans=max(grid[i][j],ans);
            }
        }
        return ans;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n-2,vector<int> (n-2,0));
        
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                ans[i][j]=getans(i,j,grid);
            }
        }
        return ans;
    }
};