class Solution {
public:
    
    void reverse(int i, int j, string &s)
    {
        while(j>=s.size())
        {
            j--;
        }
        while(i<j )
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    
    string reverseStr(string s, int k) {
        int i=0;
        int n=s.size();
        
        while(i<n)
        {
            reverse(i,i+k-1,s);
            i+=2*k;
        }
        return s;
    }
};