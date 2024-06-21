class Solution {
public:
    
    bool isPossible(int k,vector<int> &position,int m)
    {
        int i=0,n=position.size();
        int nextPossible=position[0]+k;
        m--;
        while(i<n)
        {
            while(i<n &&position[i]<nextPossible)
            {
               i++;
            }
            if(i<n)
            {
                nextPossible=position[i]+k;
                m--;
                i++;
            }
            
        }
        return m<=0;
        
    }
    
    int maxDistance(vector<int>& position, int m) {
        int n =position.size();
        sort(position.begin(),position.end());
        int l=1, r=position[n-1];
        while(l<r)
        {
            int mid=(l+r)/2;
            if(isPossible(mid,position,m))
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return l-1;
    }
};