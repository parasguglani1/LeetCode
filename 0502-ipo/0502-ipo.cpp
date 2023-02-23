class Solution {
public:
         bool cmp(pair<int,int> a , pair<int,int> b)
        {
            if(a.first<b.first)
            {
                return true;
            }
            else if (a.first>b.first)
            {
                return false;
            }
            else
            {
                return b.second<a.second;
            }
        }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
   
        int n=capital.size();
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++)
        {
            vp[i]={capital[i],profits[i]};
        }
        sort(vp.begin(),vp.end());
            int i=0;
            priority_queue<int> pq;
            while(k--)
            {
                while(i<n &&vp[i].first<=w)
                {
                    pq.push(vp[i++].second);
                }
                if(pq.empty())
                {
                    break;
                }
                w+=pq.top();
                pq.pop();
            }
        return w;

    }
};