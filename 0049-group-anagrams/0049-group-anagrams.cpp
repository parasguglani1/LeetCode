class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string >> ans;
        int n=strs.size();
        map<string,vector<string>> mp;
        for(int i=0;i<n;i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(strs[i]);
        }
        for(auto x: mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};