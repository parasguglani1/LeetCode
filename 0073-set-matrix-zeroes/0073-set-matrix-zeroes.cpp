class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        set<int> row,cols;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    row.insert(i);
                    cols.insert(j);
                }
            }
            
        }
        
        for(auto x:row)
        {
            for(int i=0;i<m;i++)
            {
                matrix[x][i]=0;
            }
        }
        for(auto x:cols)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][x]=0;
            }
        }

        
    }
};