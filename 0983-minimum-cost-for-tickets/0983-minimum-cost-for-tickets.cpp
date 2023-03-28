class Solution
{
    public:
        int findans(vector<int> &d, vector<int> &c, vector< int > &dp, int in)
        {
            if (in == d.size())
                return 0;	// if we have ready to n days 
            if (dp[ in ] != -1)
                return dp[ in ];	// if we have already calculated the value

            int sum = 0;
            int val = d[ in ];

            sum = c[0] + findans(d, c, dp, in +1);	// if we purchase 1 days ticket

            auto it = lower_bound(d.begin(), d.end(), val + 7);
            sum = min(sum, c[1] + findans(d, c, dp, (it - d.begin())));	// if we purchase 7 days ticket

            it = lower_bound(d.begin(), d.end(), val + 30);
            sum = min(sum, c[2] + findans(d, c, dp, (it - d.begin())));	// if we purchase 30 days ticket

            return dp[ in ] = sum;	// assinging the min ans among all way and return it 

        }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int d = days.size();
        vector<int> dp(d, -1);

        return findans(days, costs, dp, 0);
    }
};