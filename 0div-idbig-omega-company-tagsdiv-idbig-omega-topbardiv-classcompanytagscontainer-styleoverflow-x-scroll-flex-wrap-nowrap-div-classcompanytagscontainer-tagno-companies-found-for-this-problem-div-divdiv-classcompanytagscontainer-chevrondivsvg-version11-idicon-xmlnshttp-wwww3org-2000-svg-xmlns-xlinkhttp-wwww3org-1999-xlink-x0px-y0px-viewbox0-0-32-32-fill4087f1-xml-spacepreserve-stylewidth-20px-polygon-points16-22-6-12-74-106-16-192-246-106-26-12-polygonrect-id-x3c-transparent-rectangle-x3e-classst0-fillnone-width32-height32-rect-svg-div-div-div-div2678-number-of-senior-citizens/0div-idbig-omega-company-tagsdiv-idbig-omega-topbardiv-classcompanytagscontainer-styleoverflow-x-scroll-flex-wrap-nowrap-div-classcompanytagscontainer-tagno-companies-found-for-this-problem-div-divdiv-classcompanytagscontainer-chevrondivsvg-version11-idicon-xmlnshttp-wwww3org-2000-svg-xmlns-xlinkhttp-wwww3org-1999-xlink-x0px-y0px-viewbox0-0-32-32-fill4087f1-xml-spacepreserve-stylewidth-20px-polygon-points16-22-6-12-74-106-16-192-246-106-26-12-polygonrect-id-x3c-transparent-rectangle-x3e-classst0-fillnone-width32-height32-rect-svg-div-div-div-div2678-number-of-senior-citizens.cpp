class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto x:details)
        {
            string str=x.substr(11,2);
            int age=stoi(str);
            if(age>60)
            {
                cnt++;
            }
        }
        return cnt;
    }
};