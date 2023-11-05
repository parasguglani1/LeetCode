class Solution {
public:
    int differenceOfSums(int n, int m) {
     //num2
        
        int num2=0;
        int temp=0;
        while(temp<=n)
        {
            num2+=temp;
            temp+=m;
        }
        int num1=(n*(n+1))/2;
        return num1-num2-num2;;
    }
};