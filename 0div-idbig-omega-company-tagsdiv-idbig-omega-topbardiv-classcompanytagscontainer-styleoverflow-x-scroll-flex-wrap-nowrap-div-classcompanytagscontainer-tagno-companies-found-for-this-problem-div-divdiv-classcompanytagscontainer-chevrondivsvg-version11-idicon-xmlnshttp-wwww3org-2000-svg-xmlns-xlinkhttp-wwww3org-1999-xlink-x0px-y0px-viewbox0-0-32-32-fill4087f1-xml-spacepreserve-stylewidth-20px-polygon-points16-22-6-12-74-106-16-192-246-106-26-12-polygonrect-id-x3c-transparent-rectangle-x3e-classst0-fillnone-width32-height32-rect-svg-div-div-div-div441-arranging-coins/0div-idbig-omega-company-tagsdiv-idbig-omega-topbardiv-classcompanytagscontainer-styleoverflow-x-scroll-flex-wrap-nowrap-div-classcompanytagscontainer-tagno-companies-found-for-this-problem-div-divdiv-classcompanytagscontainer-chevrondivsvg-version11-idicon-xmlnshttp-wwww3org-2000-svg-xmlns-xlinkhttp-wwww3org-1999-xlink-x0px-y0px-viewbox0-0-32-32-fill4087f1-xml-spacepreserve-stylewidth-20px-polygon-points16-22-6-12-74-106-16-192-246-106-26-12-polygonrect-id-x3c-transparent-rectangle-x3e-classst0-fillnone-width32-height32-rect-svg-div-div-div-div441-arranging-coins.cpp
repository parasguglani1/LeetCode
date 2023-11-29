class Solution {
public:
    int arrangeCoins(int n) {
        long long temp=0;
        
        // if(n==1)
        // {
        //     return n;
        // }
        int i=0;
        int ans=0;
        while(temp<=n-i)
        {
            temp+=i;
            i++;
            
        }
        return i-1;
    }
};