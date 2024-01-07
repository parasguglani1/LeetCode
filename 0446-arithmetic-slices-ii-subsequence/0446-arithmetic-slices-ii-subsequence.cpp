
#define ll long long
class Solution
{
    public:
        int numberOfArithmeticSlices(vector<int> &A)
        {

            ll n = A.size();
            if (n < 3) return 0;
           	// map of index vs (map of diff vs count) i.e count of subseq with diff = diff ending at index 
            unordered_map<ll, map<ll, ll>> dp;
            ll ans = 0;
            for (ll i = 1; i < n; i++)
            {
                for (ll j = i - 1; j >= 0; j--)
                {
                    ll diff = (ll) A[i] - (ll) A[j];

                    if (dp[j].find(diff) != dp[j].end())
                    {
                        ans += dp[j][diff];	// this will always add subsequence of length >=3 
                        dp[i][diff] += dp[j][diff];	// All of j to be included (i.e arr[i] is appended to all subseq of j)
                    }
                    dp[i][diff] += 1;	// +1 for the subsequence arr[j],arr[i]

                }
            }
            return ans;
        }
};