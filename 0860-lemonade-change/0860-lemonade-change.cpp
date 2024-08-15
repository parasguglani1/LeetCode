class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5=0,count10=0;
        
        for (auto x:bills)
        {
            if(x==10)
            {
                if(count5==0)
                {
                    return false;
                }
                count5--;
                count10++;
            }
            else if (x==5)
            {
                count5++;
            }
            else 
            {
                if(count10>0 &&count5>0)
                {
                    count10--;
                    count5--;
                }
                else if(count5>2)
                {
                    count5-=3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};