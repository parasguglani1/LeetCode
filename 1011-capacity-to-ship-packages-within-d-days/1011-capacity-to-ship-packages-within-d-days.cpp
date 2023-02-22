class Solution
{
    public:
    #define ll long long
    int dy = 0;
    vector<int> weight;
    int n;
    bool check(int w)
    {
        int day = dy;
        int i = 0;
        int curr = 0;
        while (day > 0)
        {
            while (i < n)
            {
                curr += weight[i];
                if (curr > w)
                {
                    curr = weight[i];
                    day--;
                }
                i++;
            }
            if (day > 0)
            {
                return true;
            }
        }
        return false;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        n = weights.size();
        weight = weights;
        dy = days;
        ll sum = 0;
        sum = accumulate(weights.begin(), weights.end(), sum);

        ll st = *max_element(weights.begin(), weights.end());
        ll end = sum;
        while (st < end)
        {
            ll mid = (st + end) / 2;
            if (check(mid))
                end = mid ;
            else
            {
                st = mid + 1;
            }

        }
        
        return st;
    }
};