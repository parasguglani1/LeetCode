class Solution
{
    public:
        bool areAlmostEqual(string s1, string s2)
        {
            int count = 0;

            for (int i = 0; i < s1.size(); i++)
            {
                if (s1[i] != s2[i])
                {
                    count++;
                }
            }

            if (count == 0)
            {
                return true;
            }
            else if (count == 2)
            {
                sort(s1.begin(), s1.end());
                sort(s2.begin(), s2.end());

                int flag = 0;

                for (int i = 0; i < s2.size(); i++)
                {
                    if (s1[i] != s2[i])
                    {
                        flag = 1;
                    }
                }
                if (flag == 1)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
};