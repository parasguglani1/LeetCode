class Solution
{
    public:
        vector<int> findAnagrams(string s, string p)
        {
            vector<int> v1(26, 0), v2(26, 0);
            int n = s.length();
            int m = p.length();
            int l = 0, r = 0;
            if(m>n)
            {
                return {};
            }
            for ( r = 0; r < m; r++)
            {
                v1[s[r] - 'a']++;
                v2[p[r] - 'a']++;
            }
            vector<int> ans;

            while (r < n)
            {
                if (v1 == v2)
                {
                    ans.push_back(l);
                }
                // cout<<l<<" "<<r<<endl;
                v1[s[l] - 'a']--;
                v1[s[r] - 'a']++;
                l++;
                r++;
            }
            
            
            // for (int i = 0; i < v1.size(); i++)
            // {
            //     cout << v1[i] << " ";
            // }
            // cout << endl;
            // for (int i = 0; i < v2.size(); i++)
            // {
            //     cout << v2[i] << " ";
            // }
            // cout << endl;

           	if (v1 == v2)
           	{
           	    ans.push_back(l);
           	}
            return ans;
        }
};