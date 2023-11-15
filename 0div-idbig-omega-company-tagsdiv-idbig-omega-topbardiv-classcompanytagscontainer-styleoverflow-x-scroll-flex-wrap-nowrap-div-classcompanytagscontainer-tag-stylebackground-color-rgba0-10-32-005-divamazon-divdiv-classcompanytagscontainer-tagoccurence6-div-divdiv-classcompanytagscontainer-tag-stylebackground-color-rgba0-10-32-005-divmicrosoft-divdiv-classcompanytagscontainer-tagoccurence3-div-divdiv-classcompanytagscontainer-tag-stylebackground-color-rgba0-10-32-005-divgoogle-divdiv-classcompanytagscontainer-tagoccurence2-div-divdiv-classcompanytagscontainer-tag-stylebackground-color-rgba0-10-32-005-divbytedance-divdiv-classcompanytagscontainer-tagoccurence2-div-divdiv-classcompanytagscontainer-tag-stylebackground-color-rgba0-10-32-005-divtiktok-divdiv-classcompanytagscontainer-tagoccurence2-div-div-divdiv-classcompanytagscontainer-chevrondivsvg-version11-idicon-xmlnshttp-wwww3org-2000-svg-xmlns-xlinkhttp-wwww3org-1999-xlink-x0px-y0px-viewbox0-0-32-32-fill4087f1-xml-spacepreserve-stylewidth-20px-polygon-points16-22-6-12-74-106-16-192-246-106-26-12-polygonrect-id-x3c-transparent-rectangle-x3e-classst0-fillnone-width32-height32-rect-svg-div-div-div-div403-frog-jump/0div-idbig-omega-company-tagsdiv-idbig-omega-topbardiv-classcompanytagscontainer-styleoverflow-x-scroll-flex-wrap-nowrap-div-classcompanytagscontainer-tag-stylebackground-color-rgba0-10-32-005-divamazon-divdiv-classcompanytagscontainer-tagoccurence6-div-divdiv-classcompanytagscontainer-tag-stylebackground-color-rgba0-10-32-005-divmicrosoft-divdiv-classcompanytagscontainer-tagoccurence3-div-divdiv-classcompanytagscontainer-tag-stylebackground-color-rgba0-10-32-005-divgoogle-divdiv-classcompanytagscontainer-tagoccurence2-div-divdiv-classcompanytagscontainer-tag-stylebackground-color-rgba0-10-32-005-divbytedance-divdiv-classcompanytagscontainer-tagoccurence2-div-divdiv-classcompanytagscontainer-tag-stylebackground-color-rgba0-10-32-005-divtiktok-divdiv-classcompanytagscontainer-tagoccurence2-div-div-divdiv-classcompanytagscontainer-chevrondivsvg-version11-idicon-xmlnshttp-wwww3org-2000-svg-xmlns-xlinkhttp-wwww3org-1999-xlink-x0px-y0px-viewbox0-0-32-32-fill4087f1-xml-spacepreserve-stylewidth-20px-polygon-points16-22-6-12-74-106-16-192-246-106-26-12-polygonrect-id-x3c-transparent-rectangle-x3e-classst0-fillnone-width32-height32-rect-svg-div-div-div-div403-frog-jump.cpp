class Solution
{
    public:
        map<int, int> mp;
    bool getans(int curr, int k, map<pair<int,int>, int> &dp)
    {
        if (k == 0)
        {
            return false;
        }
        auto it = mp.find(curr);
        if (it == mp.end())
        {
           	// cout<<'h';
            return false;
        }
        if (curr < mp.begin()->first || curr > mp.rbegin()->first)
        {
            return false;
        }
        if (curr == mp.rbegin()->first)
        {
            return true;
        }

        bool ispossible = false;
        pair<int, int> p = { curr,
            k
        };
        if (dp.find(p) != dp.end())
        {
            return dp[p];
        }

        int newcurr = curr + k;
        // int takeprev = getans(newcurr - 1, k - 1,dp);
        // int takek = getans(newcurr, k,dp);
        // int takenext = getans(newcurr + 1, k + 1,dp);

        return dp[p] = getans(newcurr - 1, k - 1,dp) || getans(newcurr, k,dp) || getans(newcurr + 1, k + 1,dp);
       	//	// return takeprev | takek | takenext;
       	// return ispossible;
    }
    bool canCross(vector<int> &stones)
    {

        map<int, int> stone;
        for (auto x: stones)
        {
            stone[x]++;
        }
        map<pair<int,int>, int> dp;
        mp = stone;
        int n = stones.size();
        int k = 1;
        return getans(stones[0] + k, k, dp);
    }
};