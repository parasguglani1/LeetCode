class Solution
{
    public:
        int garbageCollection(vector<string> &garbage, vector<int> &travel)
        {
            int n = garbage.size();

            int lastG = -1, lastP = -1, lastM = -1;

            int psum = 0, gsum = 0, msum = 0;

            vector<int> prefsum(n + 1);
            prefsum[0] = 0;
            for (int i = 1; i < n ; i++)
            {
                prefsum[i] = prefsum[i - 1] + travel[i - 1];
            }
           	// int mcount=0,pcount=0,gcount=0;
            for (int i = n - 1; i >= 0; i--)
            {
                string str = garbage[i];

                msum += count(str.begin(), str.end(), 'M');
                psum += count(str.begin(), str.end(), 'P');
                gsum += count(str.begin(), str.end(), 'G');

               	// gsum+=str.count('G')
               	// psum+=str.count('P')

                bool hasM = str.find('M') != string::npos;
                bool hasG = str.find('G') != string::npos;
                bool hasP = str.find('P') != string::npos;

                if (lastG == -1 && hasG)
                {
                    lastG = i;
                }

                if (lastP == -1 && hasP)
                {
                    lastP = i;
                }
                if (lastM == -1 && hasM)
                {
                    lastM = i;
                }
            }
            for(int i=0;i<=n;i++)
            {
                // cout<<prefsum[i]<<' ';
            }
// cout<<lastG<<' '<<lastP<<' '<<lastM<<endl;
            int ans = 0;
            if (lastG != -1)
            {
                ans += prefsum[lastG];
            }
            if (lastP != -1)
            {
                ans += prefsum[lastP];
            }
            if (lastM != -1)
            {
                ans += prefsum[lastM];
            }
           	// ans+=prefsum[lastG]+prefsum[lastP]+prefsum[lastM];
            ans += psum + gsum + msum;
            return ans;
        }
};