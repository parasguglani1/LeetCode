class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       map<int,int> mp;
        for(auto x:arr)
        {
            mp[x]++;
        }
        set<int> freq;
        for(auto x:mp)
        {
            if(freq.find(x.second)!=freq.end())
            {
                return false;
                
            }
            freq.insert(x.second);
            
        }
        return true;
    }
};