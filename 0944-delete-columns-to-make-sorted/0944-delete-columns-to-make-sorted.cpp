class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        int count=0;
        int i=0,j=0;
        
        
            while(j<m)
            {
                if(strs[i][j]>strs[i+1][j])
                {
                    count++;
                    j++;
                    i=0;
                }
            else
            {
                i++;
                if(i==n-1)
                {
                    j++;
                    i=0;
                }
            }
               
            }
        
        return count;
    }
};