class Solution
{
    public:
        int checkRecord(int n)
        {
            if (n == 1) return 3;

            int m = 1000000007;
            long long *A = new long long[n];
            long long *P = new long long[n];
            long long *L = new long long[n];

            P[0] = 1;
            L[0] = 1;
            A[0] = 1;

            L[1] = 3;

            A[1] = 2;
            if (n > 2)
            {
                A[2] = 4;
            }

            for (int i = 1; i < n; i++)
            {
                A[i - 1] %= m;
                P[i - 1] %= m;
                L[i - 1] %= m;

                P[i] = ((A[i - 1] + P[i - 1]) % m + L[i - 1]) % m;

                if (i > 1) L[i] = ((A[i - 1] + P[i - 1]) % m + (A[i - 2] + P[i - 2]) % m) % m;

                if (i > 2) A[i] = ((A[i - 1] + A[i - 2]) % m + A[i - 3]) % m;
            }
           	return ((A[n - 1] % m + P[n - 1] % m) % m + L[n - 1] % m) % m;
        }
};