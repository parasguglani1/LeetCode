class Solution
{
    public:
        string fractionAddition(string s)
        {
            vector<int> numerator, denominator;

            int n = s.size();
            string curr = "";
            bool islastDig = false;
            int num = 0;

           	// if / add whatever in string to numerator
           	//if sign after digit add to denom and change islast dig to true
           	//if sign before digit add to curr

            for (int i = 0; i < n; i++)
            {
                char c = s[i];
                if (c == '-' || c == '+')
                {
                    if (curr != "")
                    {
                        int num = stoi(curr);
                        denominator.push_back(num);
                    }
                    curr = "";
                    curr += c;
                }
                else if (c == '/')
                {
                    int num = stoi(curr);
                    numerator.push_back(num);
                    curr = "";
                }
                else
                {
                    curr += c;
                }
            }
             num = stoi(curr);

            denominator.push_back(num);

            n = numerator.size();
            int lcm = 1;
            for (auto x: denominator)
            {
                int gcd = __gcd(lcm, x);
                lcm = (lcm *x) / gcd;
            }

            for (int i = 0; i < n; i++)
            {
                int d = denominator[i];
                int n = numerator[i];
                int multi = lcm / d;
                numerator[i] *= multi;
            }
            int sm = 0;

            for (auto x: numerator)
            {
                sm += x;
            }
            int largestfact = __gcd(sm, lcm);
            sm /= largestfact;
            lcm /= largestfact;
            string ans = "";
            if(lcm<0)
            {
                lcm*=-1;
                sm*=-1;
            }

            ans += to_string(sm) + '/' + to_string(lcm);

            return ans;
        }
};