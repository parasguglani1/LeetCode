class Solution {
public:
    static bool cmp(int &a,int &b)
    {
        int bit1=__builtin_popcount(a);
        int bit2=__builtin_popcount(b);
        if(bit1!=bit2)
        {
            return bit1<bit2;
        }
        return a<b;

    }
    vector<int> sortByBits(vector<int>& arr) {
     sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};