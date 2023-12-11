class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int n=arr.size();
        int cnt=1;
        int curr=-1;
        for(int i=0;i<n;i++)
        {
            if(curr==arr[i])
            {
                cnt++;
                if(cnt>n/4)
                {
                    return curr;
                }
            }
            else
            {
                cnt=1;
                curr=arr[i];
                
            }
            
        }
        return arr[n-1];
    }
};