class Solution
{
    public:
        int minCost(string colors, vector<int> &neededTime)
        {
           	// aaa  
            int n = colors.size();
            int ans = 0;
            int mn = INT_MIN;
            int i = 1;
            int sm = 0;

            while (i < n)
            {
                if (colors[i] == colors[i - 1])
                {
                    if (mn == INT_MIN)
                    {
                        sm += neededTime[i] + neededTime[i - 1];
                        mn = max(neededTime[i], neededTime[i - 1]);
                    }
                    else
                    {
                        mn = max(mn, neededTime[i]);
                        sm += neededTime[i];
                    }
                }
                else
                {
                    if (mn != INT_MIN)
                    {
                        ans -= mn;
                        ans += sm;
                        sm = 0;
                        mn = INT_MIN;
                    }
                }
                i++;
            }

            if (mn != INT_MIN)
            {
                ans -= mn;
                ans += sm;
            }

            return ans;
        }
};