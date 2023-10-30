class Solution {
public:
//     static bool cmp(int &a,int &b)
//     {
//         int bit1=__builtin_popcount(a);
//         int bit2=__builtin_popcount(b);
//         if(bit1!=bit2)
//         {
//             return bit1<bit2;
//         }
//         return a<b;

//     }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            mp[__builtin_popcount(arr[i])].push_back(arr[i]);
        }
        int i=0;
        for(auto x:mp)
        {
            for(auto y:x.second)
            arr[i++]=y;
            
        }
        return arr;
     // sort(arr.begin(),arr.end(),cmp);
        // return arr;
    }
};