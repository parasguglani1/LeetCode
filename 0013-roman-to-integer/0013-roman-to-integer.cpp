class Solution {
public:
int romanToInt(string s) {
  int total = 0;

  
    unordered_map<char, int> val{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int nn=s.length();
    for (int i = 0; i < nn; i++)
    {
      (val[s[i]] < val[s[i + 1]]) ? total -= val[s[i]] : total += val[s[i]];
      cout<<s[i+1]<<endl;
    }
    return total;
}};
