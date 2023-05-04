class Solution {
public:
    string predictPartyVictory(string senate) {
     stack<char> st;
        for(int i = 0;i<senate.size();i++)
        {
            //if stack is empty we will push element here
            if(st.empty())
            {
                st.push(senate[i]);
            }
            else
            {
                //here stack is not empty
                //so we will check if its same as stack top or different
                //if its not same then we will add character at the end of orginal string
                //then remove the character from stack as we have added it on orginal string for another round.
                if(st.top() != senate[i])
                {
                    char x = st.top();
                    st.pop();
                    senate += x;
                }
                else
                {
                    st.push(senate[i]);
                }
            }
        }
        string ans ="";
        //here we will check stack top
        //after all round similation only on character will left that will be the winner
        if(st.top() == 'R')
        {
            ans = "Radiant";
        }
        else
        {
            ans = "Dire";
        }
        return ans;
    }
};
