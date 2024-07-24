class Solution
{
    public:
        vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
        {
            int n = nums.size();

            map<int,vector<int>> mp;
            for (auto x: nums)
            {
                string str = to_string(x);

                for (auto &y: str)
                {
                    int dig = y - '0';
                    int replaced = mapping[dig];
                    y = replaced + '0';
                }

                int cur = stoi(str);
                mp[cur].push_back(x);
            }
            vector<int> ans;
            for(auto x:mp)
            {
                for(auto y:x.second)
                {
                    ans.push_back(y);
                }
            }

            return ans;
        }
};