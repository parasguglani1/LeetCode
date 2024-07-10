class Solution {
public:
    int minOperations(vector<string>& logs) {
        int val=0;
        for(auto &x:logs)
        {
            if(x=="../")
            {
                val=max(0,val-1);
            }
            else if(x=="./")
            {
                continue;
            }
            else
            {
                val++;
            }
        }
        return val;
    }
};