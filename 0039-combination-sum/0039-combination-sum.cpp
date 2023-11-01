class Solution
{
    public:

        void helper(int i, int curr, int target, vector<vector < int>> &ans, vector< int > &temp, vector< int > candidates)
        {
            if (i >= candidates.size())
            {
                return;
            }
           	//base
            if (curr > target)
            {
                return;
            }
            if (curr == target)
            {
                ans.push_back(temp);
                return;
            }
           	//take

            curr += candidates[i];
            temp.push_back(candidates[i]);
            helper(i, curr, target, ans, temp, candidates);

           	//not take
            curr -= candidates[i];
            temp.pop_back();
            helper(i + 1, curr, target, ans, temp, candidates);
        }

    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector < int>> ans;

       	//take
        int curr = 0;
        vector<int> temp;
        helper(0, curr, target, ans, temp, candidates);
        return ans;
    }
};