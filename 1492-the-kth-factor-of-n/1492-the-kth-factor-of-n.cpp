class Solution {
public:
    int kthFactor(int n, int k) {
        int cnt=0;
        int i=1;
        while(cnt<k &&i<=n)
        {
            
            if(n%i==0)
            {
                cnt++;   
            }
            if(cnt==k)
            {
                return i;
            }
            i++;
        }
        
        return -1;
    }
};