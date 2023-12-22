class Solution
{
    public:
        vector<int> exclusiveTime(int n, vector<string> &logs)
        {
            stack<vector< int>> st;
            vector<int> ans(n,0);
            int m=logs.size();
            int prevtime=0;
            
            for(int i=0;i<m;i++)
            {
                string str=logs[i];
                stringstream ss(str);
                string word="";
                
                string str1,str2,str3;
                getline(ss,str1,':');
                getline(ss,str2,':');
                getline(ss,str3,':');
                    
                int id=stoi(str1);
                int ts=stoi(str3)+1;
                
                if(str2=="start")
                {
                    if(!st.empty())
                    {
                        auto &v=st.top();
                        int idd=v[0];                        
                        // cout<<v[0]<<endl;
                        ans[idd]+=ts-prevtime;
                    }
                    st.push({id,ts});
                    prevtime=ts;
                    
                }
                else
                {
                    ans[id]+=ts-prevtime+1;
                    prevtime=ts+1;
                    st.pop();
                    
                    
                }
  
                
                
            }
            return ans;
        }
};