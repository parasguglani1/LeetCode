class Solution
{
    public:
        vector<int> getRow(int n)
        {
            vector<vector < int>> v;
            vector<int> v1;

            if (n == 0)
            {
                v1.push_back(1);
                return v1;
            }
            else if (n == 1)
            {
                vector<int> v1;
                v1.push_back(1);
                v1.push_back(1);
                return v1;
            }
            else
            {
                vector<int> temp2;
                temp2.push_back(1);
                v.push_back(temp2);
               	// vector<int> v1;
               	// v1.push_back(1);
               	// v1.push_back(1);
               	// v.push_back(v1);

                for (int i = 1; i < n + 1; i++)
                {
                    vector<int> temp;
                    temp.push_back(1);
                    for (int j = 1; j < i; j++)
                    {
                        temp.push_back(v[i - 1][j] + v[i - 1][j - 1]);
                    }
                    temp.push_back(1);
                    v.push_back(temp);
                }
                return v[n];
            }
        }
};