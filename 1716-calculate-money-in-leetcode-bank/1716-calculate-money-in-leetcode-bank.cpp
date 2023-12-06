class Solution
{
    public:
        int totalMoney(int n)
        {
            int sum = 0;

            int times = n / 7;

           	    sum+=times*28;
           	    times-=1;
           	    int modsum=(times*(times+1))/2;
           	    modsum*=7;
           	    sum+=modsum;
            int left = (n) % 7;
            sum += (times+1) * left;
            sum += (left *(left + 1)) / 2;

            return sum;
        }
};