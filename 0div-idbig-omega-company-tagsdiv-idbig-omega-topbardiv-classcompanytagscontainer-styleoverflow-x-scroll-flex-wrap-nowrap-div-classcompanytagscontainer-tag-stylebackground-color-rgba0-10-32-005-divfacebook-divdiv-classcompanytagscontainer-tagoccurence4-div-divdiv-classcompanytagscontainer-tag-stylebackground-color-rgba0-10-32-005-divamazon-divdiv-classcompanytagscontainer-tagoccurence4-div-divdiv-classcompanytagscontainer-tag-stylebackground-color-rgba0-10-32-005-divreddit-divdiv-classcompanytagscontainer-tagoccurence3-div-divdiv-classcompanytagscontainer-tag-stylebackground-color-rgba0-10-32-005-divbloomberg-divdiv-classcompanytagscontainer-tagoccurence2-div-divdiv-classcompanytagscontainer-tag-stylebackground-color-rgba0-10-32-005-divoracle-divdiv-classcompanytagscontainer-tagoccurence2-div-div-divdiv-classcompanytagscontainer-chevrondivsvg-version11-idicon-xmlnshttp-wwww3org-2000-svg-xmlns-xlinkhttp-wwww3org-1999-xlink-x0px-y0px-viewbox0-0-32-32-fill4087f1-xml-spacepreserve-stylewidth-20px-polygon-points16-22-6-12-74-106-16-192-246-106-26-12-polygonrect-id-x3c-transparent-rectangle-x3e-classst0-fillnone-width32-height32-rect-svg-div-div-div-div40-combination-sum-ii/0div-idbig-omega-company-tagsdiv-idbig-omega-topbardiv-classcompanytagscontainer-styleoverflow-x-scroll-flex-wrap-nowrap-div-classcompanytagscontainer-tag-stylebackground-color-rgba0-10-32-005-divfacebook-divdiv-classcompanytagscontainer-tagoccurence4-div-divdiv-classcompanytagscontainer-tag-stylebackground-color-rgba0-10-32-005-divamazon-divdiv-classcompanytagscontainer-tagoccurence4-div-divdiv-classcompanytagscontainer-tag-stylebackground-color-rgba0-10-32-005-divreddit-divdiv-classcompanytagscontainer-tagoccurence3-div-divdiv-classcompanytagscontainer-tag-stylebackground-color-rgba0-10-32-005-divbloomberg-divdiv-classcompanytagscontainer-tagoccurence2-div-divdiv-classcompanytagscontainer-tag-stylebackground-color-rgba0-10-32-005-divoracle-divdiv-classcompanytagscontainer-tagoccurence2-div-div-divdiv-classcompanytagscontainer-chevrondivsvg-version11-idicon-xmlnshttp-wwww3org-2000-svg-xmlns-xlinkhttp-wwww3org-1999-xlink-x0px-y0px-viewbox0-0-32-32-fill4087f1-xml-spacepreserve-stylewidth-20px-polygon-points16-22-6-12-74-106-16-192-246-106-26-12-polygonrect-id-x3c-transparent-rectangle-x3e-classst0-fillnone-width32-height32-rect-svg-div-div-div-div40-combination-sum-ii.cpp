class Solution
{
    public:
 public:
        vector<vector < int>> ans;
    void getcombo(vector<int> &candidates, int target, vector<int> currComb, int currSum, int currIndex)
    {
        if (currSum > target) return;
        if (currSum == target)
        {
            ans.push_back(currComb);
            return;
        }
        for (int i = currIndex; i < candidates.size(); i++)
        {
            if(i>currIndex &&candidates[i]==candidates[i-1])
            {
                continue;
            }
            currComb.push_back(candidates[i]);
            currSum += candidates[i];
            getcombo(candidates, target, currComb, currSum, i+1);
            currComb.pop_back();
            currSum -= candidates[i];
        }
    }
    vector<vector < int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        getcombo(candidates, target, {}, 0, 0);
        return ans;
    }
};