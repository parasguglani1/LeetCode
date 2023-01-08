class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=1;
        for(int i=0;i<n;i++)
        {
            map<double,int> mp;
            for(int j=0;j<n;j++)
            {
                if (j != i)

                {
                double slope=(points[j][1]-points[i][1])*1.0;
                slope/= points[j][0]-points[i][0];
                mp[slope]++;
            }
            }
            for(auto x: mp)
            {
            ans=max(ans,x.second+1);
                
            }
            
        }
  
    return ans;
    }
};