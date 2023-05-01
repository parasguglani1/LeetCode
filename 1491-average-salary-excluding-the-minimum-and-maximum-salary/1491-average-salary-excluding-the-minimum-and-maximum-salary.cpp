class Solution {
public:
    double average(vector<int>& salary) {
        int n=salary.size();
        int sum=accumulate(salary.begin(),salary.end(),0);
        int mn=*min_element(salary.begin(),salary.end());
        int mx=*max_element(salary.begin(),salary.end());
        sum-=mx+mn;
        return (double)sum/(n-2);
        
    }
};