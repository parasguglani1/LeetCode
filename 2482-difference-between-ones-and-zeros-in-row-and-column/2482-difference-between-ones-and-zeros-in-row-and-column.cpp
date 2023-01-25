class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> ans=grid;
     vector<int> rows;
        
        for(int i=0;i<m;i++)
        {
            int ones=0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    ones++;
                }
                
            }
            rows.push_back(ones);
            
        }
        
        vector<int> cols;
        
         for(int i=0;i<n;i++)
        {
            int ones=0;
            for(int j=0;j<m;j++)
            {
                if(grid[j][i]==1)
                {
                    ones++;
                }
                
            }
            cols.push_back(ones);
            
        }
        
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int ones=rows[i]+cols[j];
                int zeros= m+n-ones;
                ans[i][j]=ones-zeros;
                
            }
            
        }
        
        return ans;
    }
};