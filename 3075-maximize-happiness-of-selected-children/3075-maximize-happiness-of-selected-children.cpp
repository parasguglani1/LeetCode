class Solution {
public:
long long maximumHappinessSum(vector<int> &happiness, int k)
{
    priority_queue<long long> pq;

    for (int i = 0; i < happiness.size(); i++)
    {
        pq.push(happiness[i]);
    }
    long long ans = 0;
    long long cnt = 0;
    while (k--)
    {
        long long x = pq.top();
        pq.pop();
        ans += max(x - cnt, 0ll);
        cnt++;
    }
    return ans;
}
};