class Solution
{
    public:
        bool checkRecord(string s)
        {
            int n = s.size();

            int acnt = 0;

            int lcnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'L')
                {
                    lcnt++;
                    if (lcnt == 3)
                    {
                        return false;
                    }
                }
                else
                {
                    lcnt = 0;
                }
                if (s[i] == 'A')
                {
                    acnt++;
                }
            }
            return acnt < 2 && lcnt < 3;
        }
};