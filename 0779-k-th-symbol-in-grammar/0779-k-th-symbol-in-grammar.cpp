class Solution {
public:
 int kthGrammar(int n, int k) {
        if(k == 1)  return 0;
        else if(k % 2)  return kthGrammar(n-1, (k+1)/2);        // If k is odd, return previous val
        else    return !kthGrammar(n-1, k/2);                   // If k is even, return previous val flipped
    }

};