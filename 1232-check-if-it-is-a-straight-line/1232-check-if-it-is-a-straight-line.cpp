class Solution
{
    public:
        bool checkStraightLine(vector<vector < int>> &coordinates)
        {
            int flag = 1;

            for (int i = 0; i < coordinates.size() - 2; i++)
            {

                if (((coordinates[i + 2][1] - coordinates[i + 1][1]) *(coordinates[i + 1][0] - coordinates[i][0])) !=
                    ((coordinates[i + 1][1] - coordinates[i][1]) *(coordinates[i + 2][0] - coordinates[i + 1][0])))
                {
                    flag = 0;
                    break;
                }
            }

            if (flag == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
};