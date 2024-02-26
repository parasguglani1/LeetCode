class Solution {
public:
    
    void solve(int s, int e, vector<int> &a,vector<int> &c,vector<int> &o)
    {
        
        if(s>=e)
            return ;
        int m = (s+e)/2;
        solve(s,m,a,c,o);
        solve(m+1,e,a,c,o);
        merge(a,c,o,s,m,e);
        
    }
    
    void merge( vector<int> &a,vector<int> &c,vector<int> &o,int s, int m , int e)
    {
        int ls = m-s+1;
        int rs = e-m;
        vector<int> l(ls),r(rs);
        
        for(int i=0;i<rs;i++)
        {
            r[i] = o[i+m+1];
        }
        
        for(int i=0;i<ls;i++)
        {
            l[i] = o[i+s];
        }
        
        int i,j,k,jump;
        i=j=jump=0;
        k=s;
        
        while(i<ls && j<rs)
        {
            if(a[l[i]] <= a[r[j]])
            {
                o[k] = l[i];
                c[l[i]]+=jump;
                i++;
            }
            else
            {
                o[k] = r[j];
                jump++;
                j++;
            }
            k++;
        }
        
         while(i<ls)
         {
             o[k] = l[i];
             c[l[i]]+=jump;
             i++;
             k++;
         }
        
        while(j<rs)
        {
            o[k] = r[j];
            j++;
            k++;
            
        }
    }
    vector<int> countSmaller(vector<int>& a) {
        int n  = a.size();
        vector<int> count(n),orignalindex(n);
        
        for(int i=0;i<n;i++)
        {
            orignalindex[i] = i;
        }
        
        solve(0,n-1,a,count, orignalindex);
            
        return count;
        
        
        
        
        
    }
};
