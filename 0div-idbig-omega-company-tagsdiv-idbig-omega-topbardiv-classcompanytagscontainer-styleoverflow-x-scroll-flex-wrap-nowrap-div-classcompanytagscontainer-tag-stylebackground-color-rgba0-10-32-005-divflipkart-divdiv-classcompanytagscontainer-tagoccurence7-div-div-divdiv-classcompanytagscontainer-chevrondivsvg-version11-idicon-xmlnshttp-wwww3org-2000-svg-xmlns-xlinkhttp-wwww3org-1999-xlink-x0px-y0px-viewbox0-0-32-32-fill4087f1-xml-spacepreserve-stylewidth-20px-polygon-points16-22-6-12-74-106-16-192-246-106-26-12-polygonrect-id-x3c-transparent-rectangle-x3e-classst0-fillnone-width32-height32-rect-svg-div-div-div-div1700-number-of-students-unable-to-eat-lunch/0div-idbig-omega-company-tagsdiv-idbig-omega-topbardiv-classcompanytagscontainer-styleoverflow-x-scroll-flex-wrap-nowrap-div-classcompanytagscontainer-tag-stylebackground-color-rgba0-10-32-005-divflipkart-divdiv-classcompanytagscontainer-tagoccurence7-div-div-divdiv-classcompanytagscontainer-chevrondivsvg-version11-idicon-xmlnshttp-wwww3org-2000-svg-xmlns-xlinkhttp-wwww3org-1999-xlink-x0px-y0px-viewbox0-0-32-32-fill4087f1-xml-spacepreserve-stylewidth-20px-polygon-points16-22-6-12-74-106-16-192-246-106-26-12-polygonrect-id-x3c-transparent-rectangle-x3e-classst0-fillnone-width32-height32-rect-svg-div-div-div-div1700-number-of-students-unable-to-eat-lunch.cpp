class Solution
{
    public:
        int countStudents(vector<int> &students, vector<int> &sandwiches)
        {
            int n = students.size();
            int skip = 0, i = 0;
            while (skip <= n && sandwiches.size()>0)
            {
                if (students[0] == sandwiches[0])
                {
                    // students.pop_front();
                    students.erase(students.begin());
                                        sandwiches.erase(sandwiches.begin());

                    skip = 0;
                }
                else
                {
                    int s = students[0];
                   	// students.pop_front();
                    students.erase(students.begin());

                    students.push_back(s);
                    skip++;
                }
            }
            return students.size();
        }
};