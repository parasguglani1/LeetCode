class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        
        int n=arr.size();

        vector<int>possibleAnswer={arr[n/4],arr[n/2],arr[3*n/4],arr[n-1]};

        for(int i=0;i<4;i++){
            int lb=lower_bound(arr.begin(),arr.end(),possibleAnswer[i])-arr.begin();
            int ub=upper_bound(arr.begin(),arr.end(),possibleAnswer[i])-arr.begin();

            if(ub-lb>n/4){
                return possibleAnswer[i];
            }
        }

        return -1;

    }
};