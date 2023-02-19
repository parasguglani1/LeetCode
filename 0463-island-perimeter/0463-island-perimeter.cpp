class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int perimeter=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    int count=0;
                    if(i+1<n &&grid[i+  1][j])
                    {
                        count++;
                    }
                    if(i-1>-1 &&grid[i-1][j])
                    {
                        count++;
                    }
                    if( j-1>-1 &&grid[i][j-1])
                    {
                        count++;
                    }
                    if(j+1 <m &&grid[i][j+1])
                    {
                        count++;
                    }
                    cout<<count<<endl;
                perimeter+=4-count;
                    
                }
            }
        }
        return perimeter;
    }
};