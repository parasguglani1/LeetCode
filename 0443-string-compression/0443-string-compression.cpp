class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            int n = chars.size();
            int cur = 0;
            int trav = 0;
            while (trav < n)
            {
                int samecount = 1;
                while (trav < n - 1 && chars[trav] == chars[trav + 1])
                {
                    trav++;
                    samecount++;
                }
                chars[cur++] = chars[trav++];

                if (samecount > 1)
                {
                    string str = to_string(samecount);
                    for (auto x: str)
                    {
                        chars[cur++] = x;
                    }
                }
            }
            return cur;
        }
};