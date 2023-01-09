class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element=0;
        for(auto x:nums)
        {
            if( count==0)
            element=x;
            if(x==element)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return element;
        
    }
};