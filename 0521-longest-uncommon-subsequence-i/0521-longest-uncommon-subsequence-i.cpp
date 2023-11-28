class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.find(b)==string::npos || b.find(a)==string::npos)
        {
            return max(a.size(),b.size());
        }
        return -1;
    }
};