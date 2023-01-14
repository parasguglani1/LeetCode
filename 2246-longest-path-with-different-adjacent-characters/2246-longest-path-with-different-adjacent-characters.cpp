class Solution {
public:
    vector<int>tree[100005];
    int ans;
    int FindLongestLength(int curr_node,string&s){
        
        int best=0,second_best=0;
        
        
        // traversing over all the child nodes of the curr_node
        for(auto child_node:tree[curr_node]){
		    // recursively trying for child nodes
            int len=FindLongestLength(child_node,s);
            
            // rejecting the current node if it's of same character
            if(s[child_node]==s[curr_node])
                continue;
            
			
			// updating the best and second_best paths that we can take from all the children of the given node
            if(len>best){
                second_best=best;
                best=len;
            }
            else if(len>second_best) {
                second_best=len;
            }
        }
        
		
	
        // now there are 3 possibilies  as discussed
		
		// however here we have reject one of the possibility as we have already selcted the
		// max from both the values
        
        // case 1 :  selecting the max of the two possible paths 
        int case1=1+best;
		
		// case 2:  
        int case2=1+best+second_best;
        
        // updating the answer
        ans=max({ans,case1,case2});
		
		
        return case1;
        
        
    }
    int longestPath(vector<int>& parent, string s) {
        for(int i=1;i<parent.size();i++)
            tree[parent[i]].push_back(i);
        
        ans=0;
        FindLongestLength(0,s);
        return ans;
    }
};
