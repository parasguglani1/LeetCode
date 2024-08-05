class Solution
{
    class Tries
    {
        private:
            Tries *links[26];
        int count = 0;
        public:
            void insert(const string &s)
            {
                Tries *node = this;
                for (const char &ch: s)
                {
                    int i = ch - 'a';
                    if (node->links[i] == NULL)
                    {
                        node->links[i] = new Tries();
                    }
                    node = node->links[i];
                }
                node->count++;
            }
        int getCount(const string &s)
        {
            Tries *node = this;
            for (const char &ch: s)
            {
                int i = ch - 'a';
                node = node->links[i];
            }
            return node->count;
        }
    };
    public:
        string kthDistinct(vector<string> &arr, int k)
        {
            Tries *tries = new Tries();
            for (const auto &i: arr)
            {
                tries->insert(i);
            }
            for (const auto &i: arr)
            {
                if (tries->getCount(i) == 1 && --k == 0)
                {
                    return i;
                }
            }
            return "";
        }
};