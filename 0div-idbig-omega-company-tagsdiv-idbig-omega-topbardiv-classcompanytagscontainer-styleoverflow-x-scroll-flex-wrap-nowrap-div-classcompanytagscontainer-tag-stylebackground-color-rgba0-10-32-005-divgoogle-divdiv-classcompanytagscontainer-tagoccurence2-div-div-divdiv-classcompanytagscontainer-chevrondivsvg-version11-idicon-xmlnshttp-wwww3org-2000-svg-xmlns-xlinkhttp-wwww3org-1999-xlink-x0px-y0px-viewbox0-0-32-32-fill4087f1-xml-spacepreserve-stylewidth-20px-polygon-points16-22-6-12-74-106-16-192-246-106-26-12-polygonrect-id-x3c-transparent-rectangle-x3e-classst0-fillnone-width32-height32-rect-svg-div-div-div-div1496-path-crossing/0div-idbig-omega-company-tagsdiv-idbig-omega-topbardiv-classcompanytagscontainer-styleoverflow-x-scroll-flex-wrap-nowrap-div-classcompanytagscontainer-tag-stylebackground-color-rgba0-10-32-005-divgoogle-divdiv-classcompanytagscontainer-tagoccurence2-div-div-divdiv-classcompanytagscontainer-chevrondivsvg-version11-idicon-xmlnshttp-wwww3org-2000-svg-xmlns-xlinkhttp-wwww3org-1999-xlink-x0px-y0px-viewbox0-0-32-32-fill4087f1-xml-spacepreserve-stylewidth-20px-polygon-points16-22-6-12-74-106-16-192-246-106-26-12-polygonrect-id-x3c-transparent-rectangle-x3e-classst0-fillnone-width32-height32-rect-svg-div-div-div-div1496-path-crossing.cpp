class Solution
{
    public:
        bool isPathCrossing(string path)
        {
            int n = path.size();
            int x = 0, y = 0;
            map<pair<int, int>, int> mp;
            mp[{0,0}]++;
            for (int i = 0; i < n; i++)
            {
                if (path[i] == 'N')
                {
                    y++;
                }
                else if (path[i] == 'S')
                {
                    y--;
                }
                else if (path[i] == 'E')
                {
                    x++;
                }
                else
                {
                    x--;
                }
                if (mp[
                    {
                        x,
                        y
                    }] > 0)
                {
                    cout << x << ' ' << y << endl;
                    cout << i << endl;
                    for (auto x: mp)
                    {
                        cout << x.first.first << ' ' << x.first.second << ' ';
                        cout << x.second << endl;
                    }
                    return true;
                }
                mp[
                {
                    x,
                    y
                }]++;
            }

            for (auto x: mp)
            {
                cout << x.first.first << ' ' << x.first.second << ' ';
                cout << x.second << endl;
            }

            return false;;
        }
};