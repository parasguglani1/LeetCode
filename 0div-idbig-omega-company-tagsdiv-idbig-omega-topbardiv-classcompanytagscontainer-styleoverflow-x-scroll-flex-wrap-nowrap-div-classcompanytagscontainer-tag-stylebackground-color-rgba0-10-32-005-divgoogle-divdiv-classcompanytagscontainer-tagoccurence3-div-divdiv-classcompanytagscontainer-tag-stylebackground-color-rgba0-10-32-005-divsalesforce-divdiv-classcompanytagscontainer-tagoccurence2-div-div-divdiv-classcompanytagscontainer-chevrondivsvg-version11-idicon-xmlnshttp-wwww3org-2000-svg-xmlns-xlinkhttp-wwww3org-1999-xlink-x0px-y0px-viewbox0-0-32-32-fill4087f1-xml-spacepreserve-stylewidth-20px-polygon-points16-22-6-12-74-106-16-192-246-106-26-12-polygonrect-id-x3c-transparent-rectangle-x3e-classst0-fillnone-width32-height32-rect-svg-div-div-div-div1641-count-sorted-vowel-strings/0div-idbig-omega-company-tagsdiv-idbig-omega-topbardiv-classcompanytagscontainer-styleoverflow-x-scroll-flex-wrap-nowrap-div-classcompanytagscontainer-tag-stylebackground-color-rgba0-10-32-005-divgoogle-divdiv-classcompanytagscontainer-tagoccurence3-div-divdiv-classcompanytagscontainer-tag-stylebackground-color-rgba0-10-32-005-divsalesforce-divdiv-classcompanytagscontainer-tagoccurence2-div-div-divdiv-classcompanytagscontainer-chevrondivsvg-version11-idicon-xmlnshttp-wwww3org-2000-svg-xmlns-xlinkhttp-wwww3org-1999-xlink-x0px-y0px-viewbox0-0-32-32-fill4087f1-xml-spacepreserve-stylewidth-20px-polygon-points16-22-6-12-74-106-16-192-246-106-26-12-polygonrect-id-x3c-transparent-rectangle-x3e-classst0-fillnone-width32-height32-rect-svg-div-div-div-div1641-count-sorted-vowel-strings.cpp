class Solution {
public:
    int countVowelStrings(int n) {
        //from **|***|****|*****|****
        //choose ways to put 4 bars in n * i.e. (n+4) fact/n fact
        
        int ans=(n+1)*(n+2)*(n+3)*(n+4);
        return ans/24;
    }
};