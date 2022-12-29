class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long ans=start^goal;
      int count=0;
        int i=0;
        while(i<32)
            
        {
        if(1 & (ans >> i))
          count++; 
        i++;
            
        }
        return count;
    }
};