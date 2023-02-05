class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();
        vector <int> ans;
        for(int i=0;i<n;i++)
        {
            int dis=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(boxes[j]=='1')
                {
                    dis+=abs(j-i);
                }
                
            }
            ans.push_back(dis);
            
        }
    return ans;
        
    }
};