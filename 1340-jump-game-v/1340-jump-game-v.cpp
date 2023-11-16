class Solution
{
    public:
        int dp[1005];
    int f(vector<int> &arr, int d, int i, int n)
    {
        int ans = 1;
        if (dp[i] != 0) return dp[i];
       	//right
        for (int j = i + 1; j <= min(i + d, n - 1) and arr[i] > arr[j]; ++j) ans = max(ans, 1 + f(arr, d, j, n));
       	//left
        for (int j = i - 1; j >= max(i - d, 0) and arr[i] > arr[j]; --j) ans = max(ans, 1 + f(arr, d, j, n));
        return dp[i] = ans;
    }
    int maxJumps(vector<int> &arr, int d)
    {
        int n = arr.size(), ans = 1;
       	//traversing every index
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, f(arr, d, i, n));
        }
        return ans;
    }
};