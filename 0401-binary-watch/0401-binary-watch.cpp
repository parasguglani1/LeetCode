#define setbits(x) __builtin_popcountll(x)

class Solution
{

    public:

        vector<string> readBinaryWatch(int turnedOn)
        {
            vector<string> times;
            string curr;
            for (int i = 0; i < 12; i++)
            {
                for (int j = 0; j < 60; j++)
                {
                    curr = "";
                    if (setbits(i) + setbits(j) == turnedOn)
                    {
                        string hours = to_string(i);
                        string mins = (j > 9) ? to_string(j) : "0" + to_string(j);
                        curr = hours + ":" + mins;
                        times.push_back(curr);
                    }
                }
            }
            return times;
        }
};