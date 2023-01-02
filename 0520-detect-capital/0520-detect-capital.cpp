class Solution {
public:
    bool detectCapitalUse(string word) {
        string up=word,low=word,firstC;
        
      transform(word.begin(),word.end(),up.begin(),::toupper);
        transform(word.begin(),word.end(),low.begin(),::tolower);
         firstC=low;
        low[0]=toupper(low[0]);
        if(word==low||word ==up|| word==firstC)
        {
            return true;

        }
        return false;
        
    }
};