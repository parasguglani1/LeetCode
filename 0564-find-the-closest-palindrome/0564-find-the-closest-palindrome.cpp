class Solution
{
    public:

        string nearestPalindromic(string n)
        {

            int len = n.length();
            if (len == 1) return to_string(stol(n) - 1);

            vector < long long > candidates;

            candidates.push_back(pow(10, len - 1) - 1);
            candidates.push_back(pow(10, len) + 1);
            long prefix = stol(n.substr(0, (len + 1) / 2));
            vector<long> nearPrefixes = { prefix - 1,
                prefix,
                prefix + 1
            };

            for (auto it: nearPrefixes)
            {
                string prefix = to_string(it);
                if (len % 2) prefix.pop_back();
                reverse(prefix.begin(), prefix.end());
                candidates.push_back(stol(to_string(it) + prefix));
            }

            long mini = LONG_MAX;
            long close = 0;
            for (auto it: candidates)
            {
                long diff = abs(it - stol(n));
                if (mini > diff && it != stol(n))
                {
                    mini = diff;
                    close = it;
                }
            }
            return to_string(close);
        }
};