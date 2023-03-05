class Solution {
public:
    bool isSameAfterReversals(int num) {
        string s1=to_string(num);
        reverse(s1.begin(),s1.end());
        int num2=stoi(s1);
        string s2=to_string(num2);
        reverse(s2.begin(),s2.begin());
        return s1==s2;
    }
};