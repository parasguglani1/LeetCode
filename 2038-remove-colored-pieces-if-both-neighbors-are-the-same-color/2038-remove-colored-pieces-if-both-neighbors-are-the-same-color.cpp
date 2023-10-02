class Solution {
public:
    bool winnerOfGame(string colors) {
        int acnt=0,bcnt=0;
        int n=colors.size();
        for(int i=1;i<n-1;i++)
        {
            if(colors[i-1]==colors[i] && colors[i]==colors[i+1])
            {
                if(colors[i]=='A')
                {
                    acnt++;
                }
                else
                {
                    bcnt++;
                }
            }
        }
        return acnt>bcnt;
    }
};