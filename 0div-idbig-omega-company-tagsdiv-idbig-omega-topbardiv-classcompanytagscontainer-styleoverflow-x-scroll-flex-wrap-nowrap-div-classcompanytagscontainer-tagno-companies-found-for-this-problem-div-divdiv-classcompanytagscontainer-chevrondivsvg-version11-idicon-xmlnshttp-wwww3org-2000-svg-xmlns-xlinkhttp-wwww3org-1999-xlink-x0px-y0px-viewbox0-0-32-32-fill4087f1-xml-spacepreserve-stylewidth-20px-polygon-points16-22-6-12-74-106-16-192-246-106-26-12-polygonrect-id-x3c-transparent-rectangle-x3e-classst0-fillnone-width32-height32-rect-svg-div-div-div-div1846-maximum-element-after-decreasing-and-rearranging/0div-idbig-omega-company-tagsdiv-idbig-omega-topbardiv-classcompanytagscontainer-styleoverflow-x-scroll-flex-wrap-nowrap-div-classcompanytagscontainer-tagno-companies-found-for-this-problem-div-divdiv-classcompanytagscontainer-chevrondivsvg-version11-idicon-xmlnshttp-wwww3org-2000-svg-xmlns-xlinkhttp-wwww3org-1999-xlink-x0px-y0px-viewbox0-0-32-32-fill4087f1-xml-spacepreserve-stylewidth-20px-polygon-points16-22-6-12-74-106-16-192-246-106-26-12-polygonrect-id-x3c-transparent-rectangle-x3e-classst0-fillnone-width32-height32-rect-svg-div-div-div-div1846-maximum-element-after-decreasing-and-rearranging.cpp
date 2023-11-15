class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
      int n=arr.size();
        sort(arr.begin(),arr.end());
        
        int ans=0;
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>cnt)
            {
                arr[i]=cnt+1;
                cnt++;
            }
            else if(arr[i]==cnt)
            {
                continue;
            }
            // else
            // {
            //     cnt++;
            //     cout<<'h';
            // }
        }
        return arr[n-1];
    }
};