class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        int l=a.size();
        int cont0=1,ans=0;
        for(int i=0;i<l;i++)
        {
            if(a[i]==1)
            {
                ans+=(cont0-1)/2;
                cont0=0;
            }
            else
            {
                cont0++;
                
            }
//             if(a[i]==a[i-1] )
//             {
//                 cont0++;
//             }
//             else
//             {
//                 ans+=(cont0-1)/2;
//                 cont0=1;
                
//             }
            
        }
        ans+=(cont0)/2;
        return ans>=n;
    }
};