class Solution
{
    public:
        string simplifyPath(string path, string ret = "", string useless = "", vector<string> stack = {}, string temp = "")
        {
            for (int i = 0; i < path.size(); i++)
            {
                for (; i < path.size() && path[i] != '/'; i++) temp.push_back(path[i]);
                temp == "." ? useless.push_back('d'), temp.clear() : temp == ".." ? stack.empty() ? useless.push_back('d'), temp.clear() : stack.pop_back(), temp.clear() : temp.empty() ? useless.push_back('d'), temp.clear() : stack.push_back(temp), temp.clear();
            }
            for (int i = 0; i < stack.size(); i++) ret += '/' + stack[i];
            return ret.empty() ? "/" : ret;
        }
};