class Solution
{
    public:
        string removeDuplicates(string &s, int k)
        {
            vector<pair<char, short>> v{{'#', 0}};
            for (const auto c: s)
            {
                if (v.back().first == c)
                    ++v.back().second;
                else
                    v.push_back({ c,
                        1 });

                if (v.back().second == k)
                    v.pop_back();
            }
            s.clear();
            for (auto[c, cnt]: v)
                s.append(cnt, c);
            return s;
        }
};