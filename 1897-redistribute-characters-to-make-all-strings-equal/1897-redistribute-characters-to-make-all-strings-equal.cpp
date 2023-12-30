class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> freq(26,0);
        
        int n=words.size();
        
        for(auto &x:words)
        {
            for(auto &y:x)
            {
                freq[y-'a']++;
            }
        }
        
        for(auto &x:freq)
        {
            
            if(x%n!=0)
            {
                return false;
            }
        }
        return true;
    }
};