class Solution
{
    public:

        void helper(int ind, int curr, int target, set<vector < int>> &ans, vector< int > &temp, vector< int > &candidates)
        {
            if (curr == target)
            {
               	// sort(temp.begin(),temp.end());
                ans.insert(temp);
                return;
            }
            if (ind == candidates.size())
            {
                return;
            }
           	//base
            if (curr > target)
            {
                return;
            }

           	//take
            for (int i = ind; i < candidates.size(); i++)
            {
                if (i == ind || candidates[i] != candidates[i - 1])
                {
                    curr += candidates[i];
                    temp.push_back(candidates[i]);
                    helper(i + 1, curr, target, ans, temp, candidates);

                    curr -= candidates[i];

                    temp.pop_back();
                }
            }
        }

    vector<vector < int>> combinationSum2(vector<int> &candidates, int target)
    {
        set<vector < int>> ans;

       	//take
        int curr = 0;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        for (auto x: candidates)
        {
           	// cout << x << endl;
        }
        vector<int> temp;
        helper(0, curr, target, ans, temp, candidates);

        vector<vector < int>> res;
        res.assign(ans.begin(), ans.end());
        return res;
    }
};