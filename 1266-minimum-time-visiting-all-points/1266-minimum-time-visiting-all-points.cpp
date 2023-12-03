class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        int x=points[0][0],y=points[0][1];
        for(int i=1;i<n;i++)
        {
            int diffx=abs(points[i][0]-x);
            int diffy=abs(points[i][1]-y);
            
            ans+=max(diffx,diffy);
            
            x=points[i][0];
            y=points[i][1];
            
        }
        return ans;
    }
};