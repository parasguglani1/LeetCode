class Solution {
public:
    string largestGoodInteger(string num) {
     int n=num.size();
        string ans="";
        for(int i=2;i<n;i++)
        {
            if(num[i]==num[i-1] && num[i]==num[i-2])
            {
                if(ans=="" || ans[0]<num[i])
                {
                    string temp="";
                    temp+=num[i];
                    temp+=num[i];
                    temp+=num[i];
                    
                    ans=temp;
                }
            }
            
        }
        return ans;
    }
};