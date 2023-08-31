class Solution
{
    public:
        int minTaps(int n, vector<int> &ranges)
        {
            vector<pair<int, int>> v(n+1);
            for (int i = 0; i < ranges.size() ; i++)
            {
                v[i] = { i - ranges[i],
                    i + ranges[i]
                };
            }
            sort(v.begin(), v.end());

            int count = 0, start_time = 0, end_time = 0, i = 0;

            while (end_time < n)
            {

                while( i < v.size() && v[i].first <= start_time)
                {
                    end_time = max(end_time, v[i].second);
                    i++;
                }
                if (start_time == end_time) return -1;
                start_time = end_time;
                count++;
            }
            return count;
        }
};