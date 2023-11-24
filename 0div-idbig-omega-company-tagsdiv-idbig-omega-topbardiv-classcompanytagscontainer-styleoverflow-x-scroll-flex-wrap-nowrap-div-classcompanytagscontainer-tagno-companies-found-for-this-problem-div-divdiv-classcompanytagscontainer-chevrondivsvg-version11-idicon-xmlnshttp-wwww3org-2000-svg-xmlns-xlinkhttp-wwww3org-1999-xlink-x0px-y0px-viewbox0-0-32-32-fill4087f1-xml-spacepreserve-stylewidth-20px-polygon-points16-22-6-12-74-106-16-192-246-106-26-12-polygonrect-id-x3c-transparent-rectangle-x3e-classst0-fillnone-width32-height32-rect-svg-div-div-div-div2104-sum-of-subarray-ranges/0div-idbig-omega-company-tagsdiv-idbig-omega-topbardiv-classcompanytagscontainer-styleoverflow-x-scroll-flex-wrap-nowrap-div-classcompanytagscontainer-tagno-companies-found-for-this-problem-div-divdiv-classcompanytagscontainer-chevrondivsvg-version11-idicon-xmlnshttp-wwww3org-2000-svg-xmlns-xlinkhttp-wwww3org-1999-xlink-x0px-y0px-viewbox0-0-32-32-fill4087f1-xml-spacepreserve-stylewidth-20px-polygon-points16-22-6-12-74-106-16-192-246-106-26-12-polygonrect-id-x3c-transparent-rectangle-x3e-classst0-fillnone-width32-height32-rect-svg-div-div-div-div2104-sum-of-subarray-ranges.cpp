class Solution
{
    public:
#define mod 1000000007;

    long long subArrayRanges(vector<int> &arr)
    {
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int mini = arr[i];
            int maxi=arr[i];
            for (int j = i; j < arr.size(); j++)
            {
                mini = min(mini, arr[j]);
                maxi=max(maxi,arr[j]);
                sum = (sum + maxi-mini);
            }
        }
        return sum;
    }
};