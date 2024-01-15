class Solution
{
    public:
        vector<vector < int>> findWinners(vector<vector < int>> &matches)
        {
            map<int, int> losses;
            for (auto x: matches)
            {

                losses[x[1]]++;
                losses[x[0]];
            }
            vector<vector<int>> ans(2,vector<int>());
            for(auto x:losses)
            {
                if(x.second==0)
                {
                    ans[0].push_back(x.first);
                }
                else if(x.second==1)
                {
                    ans[1].push_back(x.first);
                }
                
            }
            return ans;
        }
};