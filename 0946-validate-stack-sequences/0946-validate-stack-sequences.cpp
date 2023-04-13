class Solution
{
    public:
        bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
        {
            int i = 0;
            int j = 0;
            int n = pushed.size();
            for (auto val: pushed)
            {
                pushed[i++] = val;
                while (i > 0 && pushed[i - 1] == popped[j])
                {
                    i--;
                    j++;
                }
            }
            return i == 0;
        }
};