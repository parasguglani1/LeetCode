class Solution
{
    public:
        double averageWaitingTime(vector<vector < int>> &customers)
        {
            int startTime, endTime = 0, n = customers.size();
            long sum = 0;
            for (auto v: customers)
            {
                startTime = max(endTime, v[0]);
                endTime = startTime + v[1];
                int waitTime = endTime - v[0];
                sum += waitTime;
            }
            return sum / double(n);
        }
};