class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>> v;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double val=arr[i];
                val/=arr[j];
                v.push_back({val,{arr[i],arr[j]}});
            }
        }
        
        sort(v.begin(),v.end());
        
        auto x=v[k-1];
        
        vector<int> ans={x.second.first,x.second.second};
        return ans;
    }
};