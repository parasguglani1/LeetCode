class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int i;
        for( i=n-1;i>=0;i--)
        {
            int dig=num[i]-'0';
            if(dig%2)
            {
             break;   
            }
        }
        return num.substr(0,i+1);
    }
};