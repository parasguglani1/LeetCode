class Solution
{
    public:
        int getLucky(string s, int k)
        {
            int n = s.length();
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                int a = s[i] - 'a' + 1;
                int dig = a / 10 + a % 10;
                sum += dig;
            }
            k--;
            int ans = 0;
            while (k-- &&sum>9)
            {
                int sum2 = 0;
                while (sum > 0)
                {
                    sum2 += sum % 10;
                    sum /= 10;
                }
                sum = sum2;
            }
            return sum;
        }
};