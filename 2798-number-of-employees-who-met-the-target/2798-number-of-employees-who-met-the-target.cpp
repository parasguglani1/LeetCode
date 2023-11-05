class Solution
{
    public:
        int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
        {
            int num = count_if(hours.begin(), hours.end(), [target](int i)->bool
            {
                return i >= target; });
            return num;
        }
};