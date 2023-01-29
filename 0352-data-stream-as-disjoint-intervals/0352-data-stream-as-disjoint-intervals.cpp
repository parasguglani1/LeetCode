class SummaryRanges
{
    public:
        set<int> s;
    SummaryRanges() {}

    void addNum(int value)
    {
        s.insert(value);
    }

    vector<vector < int>> getIntervals()
    {
        if (s.size() == 0)
        {
            return {
		{}
            };
        }
        vector<vector < int>> ans;
        int start = *s.begin();
        int end = *s.begin();
        auto it2 = s.end();
        it2--;
        for (auto it = s.begin(); it != it2; it++)
        {
            auto it3 = it;
            it3++;
            if (*it3 - *it <= 1)
            {
                end = *it3;
            }
            else
            {
                ans.push_back({ start,
                    *it });
                start = *it3;
                end = *it3;
            }
        }
        ans.push_back({ start,
            end });
        return ans;
    }
};

/**
 *Your SummaryRanges object will be instantiated and called as such:
 *SummaryRanges* obj = new SummaryRanges();
 *obj->addNum(value);
 *vector<vector < int>> param_2 = obj->getIntervals();
 */