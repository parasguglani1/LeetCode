class Solution
{
    public:
        int countVowelStrings(int n)
        {
            int a = 1, e = 1, o = 1, i = 1, u = 1;
            for (int j = 1; j < n; j++)
            {
                int na = a;
                int ne = a + e;
                int ni = a + e + i;
                int no = a + e + i + o;
                int nu = a + e + i + o + u;

                // cout<<a<<' '<<e<<' '<<i<<' '<<o<<' '<<u<<endl;
                // cout<<na<<' '<<ne<<' '<<ni<<' '<<no<<' '<<nu<<endl;
                a = na;
                e = ne;
                i = ni;
                o = no;
                u = nu;
                // cout<<a<<' '<<e<<' '<<i<<' '<<o<<' '<<u<<endl;
            }
            // cout<<e<<endl;

            return a + e + i + o + u;
        }
};