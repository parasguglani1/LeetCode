class Solution
{
    public:
        long long minOperations(vector<int> &nums1, vector<int> &nums2, int k)
        {
            long long pdiff = 0, ndiff = 0, n = nums1.size();	// Initialize variables to track positive and negative differences, and the size of the input vectors
            for (int i = 0; i < n; i++)
            {
                int diff = nums1[i] - nums2[i];	// Calculate the difference between the corresponding elements in the input vectors
                if (diff > 0)	// If the difference is positive, add it to the pdiff variable
                {
                    pdiff += diff;
                }
                else	// If the difference is negative, add the absolute value to the ndiff variable
                {
                    ndiff -= diff;
                }
            }
            if (pdiff == 0 && ndiff == 0)	// If both pdiff and ndiff are zero, no operations are needed, so return 0
            {
                return 0;
            }
            if (k == 0 || pdiff != ndiff || pdiff % k != 0)	// If k is zero or if pdiff is not equal to ndiff, or if pdiff is not divisible by k, it's not possible to make the vectors equal, so return -1
            {
                return -1;
            }
            return pdiff / k;	// Otherwise, return the value of pdiff divided by k, which is the minimum number of operations needed to make the two input vectors equal.
        }
};