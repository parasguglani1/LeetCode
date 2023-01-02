class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_set<int> sti,stj;
       for(int i=0;i<matrix.size();i++)
          {
           for(int j=0;j<matrix[i].size();j++)
           {
               if(matrix[i][j]==0)
               {
                   sti.insert(i);
                   stj.insert(j);
               }
               
           }
       }
        
        for(auto x: sti)
        {
            for(int j=0;j<n;j++)
            {
                matrix[x][j]=0;
            }
        }
        for(auto x: stj)
        {
            for(int j=0;j<m;j++)
            {
                matrix[j][x]=0;
            }
        }
        
        
    
    
    
    }
};