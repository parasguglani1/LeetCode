class LFUCache
{
    public:
        LFUCache(int capacity)
        {
            size = capacity;
            m.clear();
            mlist.clear();
            mcount.clear();
        }

    int get(int key)
    {
        if (m.count(key) == 0) return -1;
        int c = m[key].second;
        mcount[c].erase(mlist[key]);
        if (mcount[c].empty())
        {
            if (minfreq == c) minfreq++;
        }
        mcount[c + 1].push_front(key);
        mlist[key] = mcount[c + 1].begin();
        m[key].second++;
        return m[key].first;
    }

    void put(int key, int value)
    {
        if (m.size() == size && m.count(key) == 0)
        {
           	// evict
            if (size == 0) return;
            int k = mcount[minfreq].back();
            m.erase(k);
            mlist.erase(k);
            mcount[minfreq].pop_back();
        }
        if (m.count(key) == 0)
        {
            m[key] = { value,
                1
            };
            minfreq = 1;
            mcount[1].push_front(key);
            mlist[key] = mcount[1].begin();
        }
        else
        {
            int c = m[key].second;
            mcount[c].erase(mlist[key]);
            if (mcount[c].empty())
            {
                if (minfreq == c) minfreq++;
            }
            mcount[c + 1].push_front(key);
            mlist[key] = mcount[c + 1].begin();
            m[key].first = value;
            m[key].second++;
        }
    }
    private:
        int size;
    int minfreq;
    unordered_map<int, pair<int, int>> m;
    unordered_map<int, list < int>> mcount;
    unordered_map<int, list<int>::iterator > mlist;

};