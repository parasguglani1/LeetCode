class Solution
{
    public:
        bool carPooling(vector<vector < int>> &trips, int capacity)
        {
            vector<int> pass(1001,0);
            for (auto x: trips)
            {
                

                    int nm = x[0];
                    // cout<<nm<<endl;
                    pass[x[1]] += nm;
                    pass[x[2]] -= nm;
                
            }
            // cout<<endl;
            int sum = 0;

            for (auto x: pass)
            {
                // cout << x << endl;
                sum += x;
                if (sum > capacity)
                {
                    // cout << x << endl;

                    return false;
                }
            }
            return true;
        }
};