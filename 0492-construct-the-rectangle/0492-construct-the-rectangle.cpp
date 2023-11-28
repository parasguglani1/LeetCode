class Solution
{
    public:
        vector<int> constructRectangle(int area)
        {
            vector<int> ans;
            for (int i = 1; i <= sqrt(area); i++)
            {
                if (area % i == 0)
                {
                    ans.clear();
                    int L = i;
                    int R = area / i;
                    ans.push_back(R);
                    
                    ans.push_back(L);
                }
            }
            return ans;
        }
};