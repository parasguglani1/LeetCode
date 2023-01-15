class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int ans=0;
        while(i<j)
        {
            int area=(j-i)*min(height[j],height[i]);
            ans=max(ans,area);
            if(height[j]<height[i])
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};