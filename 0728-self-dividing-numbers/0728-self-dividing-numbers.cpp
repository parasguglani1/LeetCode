class Solution {
public:
    bool isSelfDividing(int num)
    {
        int temp=num;
        while(temp>0)
        {
            int dig=temp%10;
            if(dig==0 ||num%dig!=0)
            {
                return false;
            }
            temp/=10;
        }
        return true;
        
    }
    vector<int> selfDividingNumbers(int left, int right) {
        int cnt=0;
        vector<int> ans;
        for(int i=left;i<=right;i++)
        {
            if(isSelfDividing(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};