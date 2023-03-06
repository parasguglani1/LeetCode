class Solution
{
    public:
        int findKthPositive(vector<int> &arr, int k)
        {
            int n = arr.size();
            for(auto a:arr)
            {
                if(a<=k)k++;
            }
            return k;
        }
};