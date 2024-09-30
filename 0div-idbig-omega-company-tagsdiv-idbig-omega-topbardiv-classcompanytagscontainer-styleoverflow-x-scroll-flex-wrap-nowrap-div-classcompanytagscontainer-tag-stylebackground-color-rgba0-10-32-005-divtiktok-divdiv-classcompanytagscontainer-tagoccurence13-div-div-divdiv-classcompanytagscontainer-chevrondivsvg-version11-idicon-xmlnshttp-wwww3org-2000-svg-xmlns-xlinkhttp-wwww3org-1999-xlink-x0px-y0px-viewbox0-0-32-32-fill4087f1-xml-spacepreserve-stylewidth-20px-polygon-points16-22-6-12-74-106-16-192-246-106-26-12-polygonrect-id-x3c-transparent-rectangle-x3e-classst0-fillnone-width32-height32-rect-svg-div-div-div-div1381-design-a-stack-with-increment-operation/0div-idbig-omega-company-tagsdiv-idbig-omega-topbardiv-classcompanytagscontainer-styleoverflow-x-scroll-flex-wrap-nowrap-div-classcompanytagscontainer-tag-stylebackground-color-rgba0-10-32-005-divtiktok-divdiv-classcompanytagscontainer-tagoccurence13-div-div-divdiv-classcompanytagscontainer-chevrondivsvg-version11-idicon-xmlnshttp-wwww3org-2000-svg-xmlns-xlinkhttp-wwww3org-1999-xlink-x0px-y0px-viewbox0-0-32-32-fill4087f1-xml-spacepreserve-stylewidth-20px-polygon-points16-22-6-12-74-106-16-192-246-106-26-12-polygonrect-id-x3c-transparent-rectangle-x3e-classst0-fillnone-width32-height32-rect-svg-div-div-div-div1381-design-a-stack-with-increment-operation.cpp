class CustomStack
{
    public:
        vector<int> arr;
    vector<int> lazy;
    int sze;
    CustomStack(int maxSize)
    {
        sze = maxSize;
    }

    void push(int x)
    {
        if (arr.size() < sze)
        {
            arr.push_back(x);
            lazy.push_back(0);
        }
    }

    int pop()
    {
        if (arr.size() == 0) return -1;
        int tp = arr.back() + lazy.back();
        arr.pop_back();
        if (arr.size() != 0) lazy[lazy.size() - 2] += lazy.back();
        lazy.pop_back();
        return tp;
    }

    void increment(int k, int val)
    {
        if (arr.size() == 0) return;
        k = min(k, (int) arr.size());
        lazy[k - 1] += val;
    }
};

/**
 *Your CustomStack object will be instantiated and called as such:
 *CustomStack* obj = new CustomStack(maxSize);
 *obj->push(x);
 *int param_2 = obj->pop();
 *obj->increment(k,val);
 */