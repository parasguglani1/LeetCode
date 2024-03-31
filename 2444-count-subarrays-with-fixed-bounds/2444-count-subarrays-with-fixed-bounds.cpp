class Solution
{
    public:
        long long countSubarrays(vector<int> &nums, int minK, int maxK)
        {
            long long ans = 0;
            int maxIdx = -1, minIdx = -1, start = 0;
            bool maxFound = false, minFound = false;

            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] < minK or nums[i] > maxK)	//case 1 out of range element 
                {
                    minFound = false;	//flush eerything 
                    maxFound = false;
                    start = i + 1;	//iske aage se shyd hme koi subarray mile 
                   	//isko inlcude krke to nahi mil skta kuki ye to khud out of bound 
                   	//i se phle wle hm phle hi calcualte kr chuke to ab i+1 wle dkeho
                }
                if (nums[i] == minK)	//case 2 if equal to minK update minIdx
                {
                    minFound = true;
                    minIdx = i;
                }
                if (nums[i] == maxK)	//case 3 if equal to maxK update maxIdx
                {
                    maxFound = true;
                    maxIdx = i;
                }

                if (maxFound == true and minFound == true)	//case 4 when we found both
                    ans += max(0, min(maxIdx, minIdx) - start + 1);	//add subarrays formed 
            }
            return ans;
        }
};