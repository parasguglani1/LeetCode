class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();
        int i=0,j=0;
        int l=0,r=0;
        while(true)
        {
            if(l==word1[i].size())
            {
                l=0;
                i++;
            }
            if(r==word2[j].size())
            {
                r=0;
                j++;
            }
            if(i==n &&j==m)
            {
                return true;
            }
            if(i==n||j==m)
            {
                return false;
            }
            char c1=word1[i][l];
            char c2=word2[j][r];
            if(c1!=c2)
            {
                return false;
            }
            l++;r++;
        }
        return true;
    }
};