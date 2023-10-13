class Solution {
public:
  
int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> nums3(nums1.size(), 0);
    int last = 0, lastInd = -1, back = 0, ans = 1;
    for (int i = 0; i < nums1.size(); ++i)
    {
        int mn = min(nums1[i], nums2[i]), mx = max(nums1[i], nums2[i]);
        if (mn >= last)
        {
            nums3[i] = mn;
        }
        else if (mx >= last)
        {
            nums3[i] = mx;
            if (lastInd == -1)
                lastInd = i;
        }
        else
        {
            nums3[i] = mn;
        }

        // check for break of the non-decreasing order
        if (mx < last)
        {
            if (lastInd != -1)
            {
                i = lastInd - 1;
                lastInd = -1;
            }
            else
                i--;
            last = 0;
            back = i + 1;
        }
        else
        {
            last = nums3[i];
            ans = max(ans, i - back + 1);
        }
    }
    return ans;
}
};