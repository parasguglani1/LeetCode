class Solution
{
    public:
        int bestTeamScore(vector<int> &scores, vector<int> &ages)
        {
            int n = scores.size();
            int dev[n];
            int ans = 0;
            vector<pair<int, int>> age_score;
            for (int i = 0; i < n; i++)
            {
                age_score.push_back({ ages[i],
                    scores[i] });
            }
            sort(age_score.begin(), age_score.end());
            for (int i = 0; i < n; i++)
            {
                dev[i] = age_score[i].second;
                for (int j = 0; j < i; j++)
                {
                    if (age_score[j].second <= age_score[i].second)
                        dev[i] = max(dev[i], dev[j] + age_score[i].second);
                }
                ans = max(ans, dev[i]);
            }
            return ans;
        }
};