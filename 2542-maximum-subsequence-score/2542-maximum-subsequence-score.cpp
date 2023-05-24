class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b, int k) {
        
        int n = a.size() ;
        long long sum =0 , ans = INT_MIN;
        priority_queue<pair<int,int>> mx;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mn;
        pair<int,int> p;
        
        for(int i=0;i<n;i++) mx.push({a[i],i});
        
        while(k--){
            p = mx.top();
            mx.pop();
            sum += p.first;
            mn.push({b[p.second],p.second});
        }
        
        ans = max(ans,sum*(long long)mn.top().first);
        
        while(!mx.empty()){
            sum -= a[mn.top().second];
            mn.pop();
            p = mx.top();
            mx.pop();
            sum += p.first;
            mn.push({b[p.second],p.second});
            ans = max(ans,sum*(long long)mn.top().first);
        }
        
        return ans;
    }
};
