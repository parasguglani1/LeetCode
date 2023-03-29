class Solution
{
    public:
        int maxSatisfaction(vector<int> &s)
        {
            sort(s.begin(), s.end());
            int n = s.size(), sum = 0;
            for (int i = n - 1; i > 0; i--)
                s[i - 1] += s[i];
            int i = 0;
            while (i < n)
            {
                if (s[i] >= 0) sum += s[i];
                i++;
            }
            return sum;
        }
};