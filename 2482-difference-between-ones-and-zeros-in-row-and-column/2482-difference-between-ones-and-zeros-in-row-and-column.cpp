class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans=grid;
        map<int,int>rows,cols;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int temp=2*rows[i]-n+2*cols[j]-m;
                ans[i][j]=temp;
            }
        }
        return ans;
        
    }
};