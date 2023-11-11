class Solution
{
    public:

        int maxProfit(vector<int> &prices)
        {
            int n = prices.size();
            int profit = 0, buyvalue = 0, sellvalue = 0, i = 0;

            while (i < n)
            {
                while (i < n - 1 && prices[i] >= prices[i + 1])
                {
                    i++;
                }
                buyvalue = prices[i];

                while (i < n - 1 && prices[i] < prices[i + 1])
                {
                    i++;
                }
                sellvalue = prices[i];
                profit += sellvalue - buyvalue;
                i++;
            }
            return profit;
        }
};