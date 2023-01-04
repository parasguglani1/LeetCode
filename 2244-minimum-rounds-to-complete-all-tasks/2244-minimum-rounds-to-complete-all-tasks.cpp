class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map <int,int> mp;
        int n=tasks.size();
        for(int i=0;i<n;i++)
        {
            mp[tasks[i]]++;
        }
        
        int count=0;
        for(auto x:mp)
        {
            int val=x.second;
            if(val==1)
            {
                return -1;
            }
            
            count+=ceil(val/3.0);
            
        }
        return count;
    }
    
};