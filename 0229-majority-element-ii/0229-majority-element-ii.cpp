class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int n=nums.size();
    vector <int> ans;
        int count2=0,count1=0,num1=0,num2=0;
        for(auto x:nums)
        {
            if(x==num1)
                count1++;
            else if(x==num2)
            {
                count2++;
            }
            else if(count1==0)
            {
                num1=x;
                count1++;
            }
            else if(count2==0)
            {
                num2=x;
                count2++;
                
            }
            else 
            {
                count1--;
                count2--;
            }
            
        }
        
        count1=0;count2=0;
        for(auto x: nums)
        {
              if(x==num1)
                count1++;
            else if(x==num2)
            {
                count2++;
            }
        }
        
        if(count1>n/3)
        {
            ans.push_back(num1);
        }
        if(count2>n/3)
        {
            ans.push_back(num2);
        }
    return ans;
    }
};