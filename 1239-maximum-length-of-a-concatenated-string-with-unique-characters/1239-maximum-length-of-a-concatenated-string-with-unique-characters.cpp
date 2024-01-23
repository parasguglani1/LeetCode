class Solution
{
    public:

        int getans(vector<string> &arr, int idx, set<char> &st, int ans)
        {
            if (idx == arr.size())
            {
                return ans;
            }
            bool isPossible = true;
            string curr = arr[idx];
            set<char> st2;
            for (auto x: curr)
            {
                if (st.find(x) != st.end() || st2.find(x) != st2.end())
                {
                    isPossible = false;
                }
                else
                {
                    st2.insert(x);
                }
            }
            int ans1 = 0, ans2 = 0;
            int curans = 0;
            if (isPossible)
            {
                //not take
                ans2 = getans(arr, idx + 1, st, ans);

               	//take
                for (int i = 0; i < arr[idx].size(); i++)
                {
                    st.insert(arr[idx][i]);
                }
                ans1 = getans(arr, idx + 1, st, ans + arr[idx].size());
                
                 for (int i = 0; i < arr[idx].size(); i++)
                {
                    st.erase(arr[idx][i]);
                }

               	
                curans = max(ans1, ans2);
            }
            else
            {
                curans = getans(arr, idx + 1, st, ans);
            }
            // cout << curans << endl;
            return curans;
        }

    int maxLength(vector<string> &arr)
    {

        int ans = 0;
        set<char> st;

        ans = getans(arr, 0, st, ans);
        return ans;
    }
};