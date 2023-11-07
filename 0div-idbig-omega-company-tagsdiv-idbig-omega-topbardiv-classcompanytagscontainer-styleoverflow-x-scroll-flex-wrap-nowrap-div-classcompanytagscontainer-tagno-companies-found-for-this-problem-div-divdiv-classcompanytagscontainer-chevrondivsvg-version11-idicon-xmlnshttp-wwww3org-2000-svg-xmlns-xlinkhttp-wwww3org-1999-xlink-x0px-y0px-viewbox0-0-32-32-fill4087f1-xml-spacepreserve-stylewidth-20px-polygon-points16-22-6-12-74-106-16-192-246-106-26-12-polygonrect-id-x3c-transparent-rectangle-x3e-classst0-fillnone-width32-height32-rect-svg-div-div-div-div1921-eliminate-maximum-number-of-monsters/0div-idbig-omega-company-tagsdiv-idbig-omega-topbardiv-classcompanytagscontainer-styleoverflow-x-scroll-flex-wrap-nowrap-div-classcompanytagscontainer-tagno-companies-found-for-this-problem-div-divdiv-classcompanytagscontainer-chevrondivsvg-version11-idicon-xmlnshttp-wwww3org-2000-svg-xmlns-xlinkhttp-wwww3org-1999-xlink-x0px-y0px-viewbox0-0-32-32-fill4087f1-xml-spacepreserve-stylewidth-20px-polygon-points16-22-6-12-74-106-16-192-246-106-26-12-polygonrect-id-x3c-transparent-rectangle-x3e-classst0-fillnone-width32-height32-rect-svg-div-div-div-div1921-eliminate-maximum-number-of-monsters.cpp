class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        
        vector<double> timetoreach(n);
        
        for(int i=0;i<n;i++)
        {
            timetoreach[i]=((dist[i]-1)/speed[i]);
        }
                            sort(timetoreach.begin(),timetoreach.end());
   
        for(int i=0;i<n;i++)
        {

            if(i>timetoreach[i])
            {
                return i;
            }
        }
        
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
//         for(int i=0;i<n;i++)
//         {
//             pair x={dist[i],speed[i]};
//             pq.push(x);
//         }
        
//         int time=1;
//         while(!pq.empty())
//         {
//             auto x=pq.top();
//             int currspeed=x.second;
//             int curdis=x.first;
//             int distravelled=currspeed*time;
//             cout<<distravelled<<' '<<time<<endl;
//             if(distravelled>curdis)
//             {
//                 return time;
                
//             }
//             time++;
//             pq.pop();
//         }
                            
        // return time;
                            return n;
    }
};