class Solution
{
    public:
        int compress(vector<char> &chars)
        {
            int n = chars.size();
            int cur = 0;
            int trav = 0;
            int samecount = 1;
            while (trav < n - 1)
            {
                if (chars[trav] == chars[trav + 1])
                {
                    samecount++;
                }
                else
                {
                    if (samecount == 1)
                    {
                        chars[cur++] = chars[trav];
                    }
                    else
                    {
                        chars[cur++] = chars[trav];
                        int digits = 0;

                        while (samecount > 0)
                        {
                            digits++;
                            chars[cur++] = samecount % 10 + '0';
                            samecount /= 10;
                        }
                        if (digits == 2)
                        {
                            swap(chars[cur - 2], chars[cur - 1]);
                        }
                        else if (digits == 3)
                        {
                            swap(chars[cur - 3], chars[cur - 1]);
                        }
                        else if (digits == 4)
                        {
                            swap(chars[cur - 4], chars[cur - 1]);
                            swap(chars[cur - 3], chars[cur - 2]);
                        }
                    }

                    samecount = 1;
                }
                trav++;
            }

            if (samecount == 1)
            {
                chars[cur++] = chars[trav];
            }
            else
            {
                chars[cur++] = chars[trav];
                int digits = 0;
                while (samecount > 0)
                {
                    chars[cur++] = samecount % 10 + '0';
                    samecount /= 10;
                    digits++;
                }
                if (digits == 2)
                {
                    swap(chars[cur - 2], chars[cur - 1]);
                }
                else if (digits == 3)
                {
                    swap(chars[cur - 3], chars[cur - 1]);
                }
                else if (digits == 4)
                {
                    swap(chars[cur - 4], chars[cur - 1]);
                    swap(chars[cur - 3], chars[cur - 2]);
                }
            }
            samecount = 1;
            return cur;
        }
};