class Solution
{
    public:
        void merge(vector<int> &a, int low,int mid,int high)
        {
            int n = mid, m = high;
            int i = low, j = mid+1, k = 0;
            vector<int> ans(high-low+1);
            while (i <= n && j <= m)
            {
                if (a[i] < a[j])
                {
                    ans[k++] = a[i++];
                }
                else
                {
                    ans[k++] = a[j++];
                }
            }

            while (i <= n)
            {
                ans[k++] = a[i++];
            }
            while (j <= m)
            {
                ans[k++] = a[j++];
            }
            for(int i=low;i<=high;i++)
            {
                a[i]=ans[i-low];
            }
        }
    
    
    void mergeSort(vector<int> &nums,int low,int high)
    {
        if(low>=high)
        {
            return;
        }
        int mid=(high-low)/2+low;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
        
        
    }
    vector<int> sortArray(vector<int> &nums)
    {
       	//MERGE SORT
        mergeSort(nums,0,nums.size()-1);
        return nums;
    
        
        
    }
};