class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        for(auto x:s)
        {
            if(x=='#')
            {
                if(!st.empty())
                {
                    st.pop();
                    
                }
            }
            else
            {
                st.push(x);
            }
            
        }
        stack<char> tt;
        
             for(auto x:t)
        {
            if(x=='#')
            {
                if(!tt.empty())
                {
                    tt.pop();
                    
                }
            }
            else
            {
                tt.push(x);
            }
            
        }
        return st==tt;
    }
};