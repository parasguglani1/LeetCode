class Solution {
public:
    int romanToInt(string s) {
    
    int num[s.length()], ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'I')
                num[i] = 1;
            else if(s[i] == 'V')
                num[i] = 5;
            else if(s[i] == 'X')
                num[i] = 10;
            else if(s[i] == 'L')
                num[i] = 50;
            else if(s[i] == 'C')
                num[i] = 100;
            else if(s[i] == 'D')
                num[i] = 500;
            else if(s[i] == 'M')
                num[i] = 1000;
        }
        
        for(int i = 0; i < s.length() - 1; i++){
            if(num[i + 1] > num[i]){
                num[i] = num[i + 1] - num[i];
                num[i + 1] = 0;
                i += 1;
            }
        }
        
        for(int i = 0; i < s.length(); i++)
            ans += num[i];
        
        return ans;
        
    }
};