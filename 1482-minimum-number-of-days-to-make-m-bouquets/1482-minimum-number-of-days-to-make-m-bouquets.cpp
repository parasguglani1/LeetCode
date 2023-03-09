class Solution
{
    public:

        int mm, kk, nn;
    vector<int> bd;
    bool check(int mid)
    {
        int cons = 0;
        int bo = 0;
        for (int i = 0; i < nn; i++)
        {
            if (bd[i] > mid)
            {
                cons=0;
              
            }
            if (bd[i] <= mid)
            {
                 cons++;
                if (cons >= kk)
                {
                    cout << i << " " << cons << endl;
                    cons = 0;
                    bo++;
                }
            }

            if (bo >= mm)
            {
                cout << bo << endl;
                return true;
            }
        }

        if (cons >= kk)
        {
            cout << nn << " " << cons << endl;

            cons = 0;
            bo++;
        }
        if (bo >= mm)
        {
            return true;
        }
        cout << bo << endl;
        return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        bd = bloomDay, mm = m, kk = k;
        int n = bloomDay.size();
        nn = n;
        long long chk=(long)m*k;
        if (n < chk)
        {
            return -1;
        }
       	// int l = *min_element(bloomDay.begin(), bloomDay.end());
        int l = 1;
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        cout << r << endl;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            cout << mid << "m" << endl;
            if (check(mid))
            {
                cout << "h" << endl;
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};