class Solution
{
    public:
        int findTheWinner(int n, int k)
        {
       vector<int> v;
        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
        }
        int cur_ind = 0;

        while (v.size() > 1) {
            int next_to_remove = (cur_ind + k - 1) % v.size();
            v.erase(v.begin() + next_to_remove);
            cur_ind = next_to_remove;
        }

        return v[0];
        }
};