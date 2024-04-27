class Solution
{
    public:
        int getans(string &ring, string &key, int cur, int idx,vector<vector<int>>& dp)
        {
            if(idx==key.size())
            {
                return 0;
            }
            if(dp[cur][idx]!=-1)
            {
                return dp[cur][idx];
            }
            int n=ring.size();
            if (key[idx] == ring[cur])
            {
                return dp[cur][idx]= 1+ getans(ring, key, cur, idx + 1,dp);
            }

            int left = -1, right = -1;
            bool canCycle = true;
            int steps = 0;
            int leftidx,rightidx;
            for (int i = cur; i > -1 || canCycle; i--)
            {
                if (ring[i] == key[idx])
                {
                    leftidx=i;
                    left = steps;
                    break;
                }
                if (i == 0 && canCycle)
                {
                    i = ring.size();
                    canCycle = false;
                }
                steps++;
            }
            // cout<<leftidx<<' '<<key[idx]<<endl;
            
            int leftTakes=1+left+getans(ring,key,leftidx,idx+1,dp);
            canCycle=true;
            steps = 0;
            for (int i = cur; i < n || canCycle; i++)
            {
                if (ring[i] == key[idx])
                {
                    rightidx=i;
                    right = steps;
                    break;
                }
                if (i == ring.size()-1 && canCycle)
                {
                    i = -1;
                    canCycle = false;
                }
                steps++;
            }
            // cout<<rightidx<<' '<<key[idx]<<endl;

            int righttakes=1+right+getans(ring,key,rightidx,idx+1,dp);
            
            return dp[cur][idx]= min(leftTakes, righttakes);
        }
    int findRotateSteps(string ring, string key)
    {
        int n=ring.size();
        int m=key.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return getans(ring, key, 0, 0,dp);
    }
};