const int mod = 1e9 + 7;

#define ll long long
class Solution
{
    public:

        int countHomogenous(string s)
        {
            int n = s.size();

            ll count = 1;
            ll sum = 0;
            for (int i = 1; i < n; i++)
            {
                if (s[i] == s[i - 1])
                {
                    count++;
                }
                else
                {
                    ll cur = ((count) *(count + 1)) / 2;
                    cur %= mod;
                    sum = sum + cur;
                    sum %= mod;
                    count = 1;
                }
            }
            // cout<<count<<' '<<n<<endl;
            ll cur = ((count) *(count + 1)) / 2;
            // cout<<cur<<endl;
            cur %= mod;
            // cout<<cur<<endl;
            sum = sum + cur;
            sum %= mod;

            return sum;
        }
};