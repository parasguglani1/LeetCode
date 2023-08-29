class Solution
{
    public:
        int bestClosingTime(string customers)
        {
            int n = customers.size();
            vector<int> ncount(n + 1), ycount(n + 1);
           	// ycount[0] = (customers[0] == 'Y');
           	// ncount[0] = (customers[0] == 'N');
            ycount[0] = 0;
            ncount[0] = 0;
            for (int i = 1; i <= n; i++)
            {
                ycount[i] = ycount[i - 1];
                ncount[i] = ncount[i - 1];
                if (customers[i-1] == 'Y')
                {
                    ycount[i]++;
                }
                else
                {
                    ncount[i]++;
                }
            }
            // ycount[n] = ycount[n - 1] + (customers[0] == 'Y');
            // ncount[n] = ncount[n - 1] + (customers[0] == 'N');

            int ind = -1;
            int mxpen = INT_MAX;
            for (int i = 0; i <= n; i++)
            {
                cout << ycount[i] << ' ';
                int curpen = ncount[i] + ycount[n] - ycount[i];
               	// cout << curpen << ' ';
               	// int curpen2 = ycount[i] + ncount[n - 1] - ncount[i];
                if (mxpen > curpen)
                {
                    mxpen = min(mxpen, curpen);
                    ind = i;
                }
            }
            return ind;
        }
};