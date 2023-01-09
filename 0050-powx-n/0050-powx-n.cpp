class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        bool neg=false;
        if (n<0)
        {
            neg=true;
        }
        n=abs(n);
        long long exp=n;
        
        while(exp>0)
        {
            if(exp&1)
            {
                ans=ans*x;
                exp-=1;
                
            }
            else
            {
                x*=x;
                exp/=2;
                
            }
        }
        if(neg)
        {
            ans= 1.0/ans;
        }
        
        return ans;
    }
};