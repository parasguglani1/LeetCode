class Solution
{
    public:
        vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
        {
            map<string, int> mp;
            for (int i = 0; i < list1.size(); i++)
            {
                mp[list1[i]] = i;
            }
            int firstind = 1001, secondind = 1001, mn = 10000;
            vector<string> ans;
            for (int i = 0; i < list2.size() ;i++)
            {

                if (mp.find(list2[i]) != mp.end())
                {
                    int j=mp[list2[i]];
                    if (i + j < mn)
                    {
                        ans.clear();
                        firstind = j;
                        secondind=i;
                        mn=i+j;
                        ans.push_back(list1[j]);
                        
                    }
                    else if(i+j==mn)
                    {
                        ans.push_back(list1[j]);
                    }
                }
            }
         
            return ans;
        }
};