class Solution {
public:
    int minAnagramLength(string s) {
        vector<int> freq(26,0);
        for(auto &x:s)
        {
            freq[x-'a']++;
        }
        
        int mxfreq=INT_MAX;
        for(auto &x: freq)
        {
            if(x!=0)
            mxfreq=min(mxfreq,x);
        }
        
        int gcd=mxfreq;
        
        for(auto &x: freq)
        {
            if(x!=0)
            {
                gcd=__gcd(gcd,x);
            }
        }
        int n=s.size();
        return n/gcd;
    }
};