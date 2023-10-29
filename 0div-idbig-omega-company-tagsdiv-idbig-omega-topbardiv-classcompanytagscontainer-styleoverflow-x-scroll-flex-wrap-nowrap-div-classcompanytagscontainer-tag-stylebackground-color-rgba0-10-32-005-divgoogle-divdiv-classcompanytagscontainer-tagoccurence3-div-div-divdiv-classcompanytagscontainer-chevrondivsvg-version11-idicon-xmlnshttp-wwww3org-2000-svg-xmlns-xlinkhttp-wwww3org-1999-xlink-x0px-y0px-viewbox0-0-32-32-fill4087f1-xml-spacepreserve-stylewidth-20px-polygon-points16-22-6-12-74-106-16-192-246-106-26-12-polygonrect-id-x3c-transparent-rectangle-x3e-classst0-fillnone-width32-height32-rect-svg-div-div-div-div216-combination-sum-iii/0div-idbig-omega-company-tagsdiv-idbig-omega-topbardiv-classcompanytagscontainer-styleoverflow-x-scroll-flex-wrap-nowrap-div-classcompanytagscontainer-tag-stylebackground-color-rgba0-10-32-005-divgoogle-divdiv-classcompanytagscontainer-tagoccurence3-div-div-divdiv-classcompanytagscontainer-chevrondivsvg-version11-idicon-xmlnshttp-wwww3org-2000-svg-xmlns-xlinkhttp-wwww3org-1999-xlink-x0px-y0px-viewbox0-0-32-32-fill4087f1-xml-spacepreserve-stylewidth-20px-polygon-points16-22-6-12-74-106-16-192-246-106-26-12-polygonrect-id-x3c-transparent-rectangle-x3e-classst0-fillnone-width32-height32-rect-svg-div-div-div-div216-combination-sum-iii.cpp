class Solution
{
    public:
        void helper(int i, vector<int> v, int n, int target, set<vector< int >> &ans, vector< int > temp)
        {
            for(int t=0;t<temp.size();t++)
            {
                cout<<temp[t]<<' ';
            }
            cout<<endl;

            if (temp.size() == n && target == 0)
            {
                cout<<"hi"<<endl;
                ans.insert(temp);
                return;
            }
            if (i >= 9)
            {
                return;
            }
            if (temp.size() < n && v[i] <= target )
            {
                helper(i + 1, v, n, target, ans, temp);

                // cout<<v[i]<<' ';
                temp.push_back(v[i]);
                target -= v[i];
                helper(i + 1, v, n, target, ans, temp);
                // temp.pop_back();
                // target += v[i];
            }
        }
    vector<vector < int>> combinationSum3(int k, int n)
    {

        vector<int> v(9);
        for (int i = 0; i < 9; i++)
        {
            v[i] = i + 1;
        }
        set<vector<int>> ans;
        vector<int> temp;
        int i = 0;
        helper(i, v, k, n, ans, temp);
        vector<vector<int> >res;
        res.assign(ans.begin(), ans.end());
        return res;
    }
};