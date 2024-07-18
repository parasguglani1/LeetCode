class Solution {
public:
    bool check(int i, string &s, vector<int> &freq){
        int k=i;
        string t=s;
        while(i<s.size()){
            vector<int> temp(26, 0);
            for(int j=0; j<k; j++){
                temp[s[i+j]-'a']++;
            }
            for(int x=0; x<26; x++){
                if(temp[x]!=freq[x])return false;
            }
            i+=k;
        }
        return true;
    }
    int minAnagramLength(string s) {
        vector<int> freq(26, 0);
        for(int i=0; i<=s.size()/2; i++){
            freq[s[i]-'a']++;
            if(s.size()%(i+1))continue;
            if(check(i+1,s,freq))return i+1;
        }
        return s.size();
    }
};
