class Solution
{
    public:
        int maxCoins(vector<int> &piles)
        {
            int n = piles.size();
            sort(piles.begin(), piles.end());
            int ans = 0;

            for (int i = n - 2; i >= n/3; i -= 2)
            {
                // cout<<piles[i]<<' ';
                ans += piles[i];
            }
            return ans;
        }
};