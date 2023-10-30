class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int r=(m)*(n)-1;
        
        int l=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            
            int row=mid/m;
            int col=mid%m;
            
            if(matrix[row][col]==target)
            {
                return true;
            }
            else if(matrix[row][col]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
            
            
        }
        return false;
    }
};