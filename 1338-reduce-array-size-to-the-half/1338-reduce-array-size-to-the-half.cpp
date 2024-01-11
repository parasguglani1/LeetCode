class Solution
{
    public:
        int minSetSize(vector<int> &arr)
        {
            map<int, int> mp;
            for (auto x: arr)
            {
                mp[x]++;
            }
            int n = arr.size();
            int sum = 0;

            vector<int> v;
            for (auto x: mp)
            {
                v.push_back(x.second);
            }
            sort(v.begin(), v.end(), greater<int> ());

            int ans = 0;
            for (int i = 0; i < v.size(); i++)
            {
                sum += v[i];
                ans++;
                if (sum >= n / 2)
                {
                    return ans;
                }
            }
            return ans;
        }
};