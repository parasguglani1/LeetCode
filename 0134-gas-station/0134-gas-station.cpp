class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     int gasavailable=0, totalcost=0;
    int n= gas.size();
gasavailable=        accumulate(gas.begin(),gas.end(),gasavailable);
totalcost=        accumulate(cost.begin(),cost.end(),totalcost);
        // cout<<gasavailable<<" "<<totalcost;
        if(gasavailable<totalcost)
        {
            return -1;
        }
        
        int curr=0; int ans=0;
        for(int i=0;i<n;i++)
        {
            if(curr<0)
            {
                curr=0;
                ans=i;
            }
            curr+=gas[i]-cost[i];
            
        }
        return ans;
    }
};