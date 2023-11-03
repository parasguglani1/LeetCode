class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //sum of k largest
        
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0;
            for(auto x:boxTypes)
            {
                
                if(truckSize>=x[0])
                {
                    truckSize-=x[0];
                    ans+=x[1]*x[0];
                }
                else
                {
                    ans+=truckSize*x[1];
                    return ans;
                }
                
            }
        return ans;
    }
};