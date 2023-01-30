class Solution {
public:
    
    int tribonacci(int n) {
        // int a[n+1];
        if(n==0)
        {    return 0;        
        }
        if(n<3)
        {
            return 1;
        }
//         a[0]=0;
//         a[1]=1;
//         a[2]=1;
//         for(int i=3;i<=n;i++)
//         {
//             a[i]=a[i-1]+a[i-2]+a[i-3];
            
//         }
//         return a[n];
        
        int first=0;
        int second,third=1;
        int fourth=0;
           for(int i=2;i<=n;i++)
        {
               fourth=third+second+first;
               first=second;
               second=third;
               third=fourth;
            
        }
        return fourth;
        
        
    }
};