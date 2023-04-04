class Solution {
public:
    int hammingWeight(uint32_t n) {
        long long int count = 0;
        int a = 0;

        while(n){
            a = n%2;
            n = n/2;

            if(a == 1){
                count++;
            }
        }

        return count;
    }
};