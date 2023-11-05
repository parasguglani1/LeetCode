class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> st;
        for(auto x:jewels)
        {
            st.insert(x);
        }
        int cnt=0;
        for(auto x:stones)
        {
            if(st.find(x)!=st.end())
            {
                cnt++;
            }
        }
        return cnt;
    }
};