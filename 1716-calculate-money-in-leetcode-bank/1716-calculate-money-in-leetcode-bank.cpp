class Solution {
public:
    int totalMoney(int n) {
        int sum=0;
        int i=0;
        int day=0;
        int curr=0;
        while(curr<n)
        {
            int week=curr/7+1;
            int a=curr%7;
            sum+=a+week;
            curr++;
        }
        return sum;
    }
};