class Solution {
public:
    bool isPowerOfFour(int n) {
        if(!n) return 0;
     while(n%4==0)
     {
         n/=4;
     }
        return n==1;
    }
};