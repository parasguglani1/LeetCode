class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            sum+=mat[i][i];
        }
        int i=0,j=n-1;
        while(i!=n)
        {
            
            sum+=mat[i][j];
            i++;
            j--;
        }
        if(n%2)
        {
            sum-=mat[n/2][n/2];
        }
        return sum;
    }
};