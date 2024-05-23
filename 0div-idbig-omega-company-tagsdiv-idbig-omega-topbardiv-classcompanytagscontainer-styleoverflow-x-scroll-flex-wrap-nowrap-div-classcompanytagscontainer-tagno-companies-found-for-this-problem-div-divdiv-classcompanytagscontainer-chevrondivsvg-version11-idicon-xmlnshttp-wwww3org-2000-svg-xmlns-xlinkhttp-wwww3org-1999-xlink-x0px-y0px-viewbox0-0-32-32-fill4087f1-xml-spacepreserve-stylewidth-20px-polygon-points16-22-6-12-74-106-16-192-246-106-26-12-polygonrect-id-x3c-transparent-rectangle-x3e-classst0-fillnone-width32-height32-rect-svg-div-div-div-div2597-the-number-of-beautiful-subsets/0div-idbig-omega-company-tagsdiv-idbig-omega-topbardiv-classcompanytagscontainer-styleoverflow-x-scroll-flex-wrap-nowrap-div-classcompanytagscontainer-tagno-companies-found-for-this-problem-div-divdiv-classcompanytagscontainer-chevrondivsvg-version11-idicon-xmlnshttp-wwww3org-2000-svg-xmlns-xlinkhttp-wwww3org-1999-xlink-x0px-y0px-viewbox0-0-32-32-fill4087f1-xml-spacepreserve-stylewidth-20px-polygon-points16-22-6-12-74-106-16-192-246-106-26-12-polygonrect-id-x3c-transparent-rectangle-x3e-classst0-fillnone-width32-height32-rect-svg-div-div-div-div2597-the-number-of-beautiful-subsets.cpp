class Solution
{
    public:

        int getans(vector<int> &nums, int &k, map<int,int> &mp, int i)
        {

            if (i == nums.size())
            {
                return 1;
            }
            int cnt = 0;
           	//take
            if (mp[nums[i]-k]==0 &&mp[nums[i]+k]==0)
            {
                mp[nums[i]]++;
                cnt += getans(nums, k, mp, i + 1);
                mp[nums[i]]--;
            }

            cnt += getans(nums, k, mp, i + 1);
            return cnt;
           	//not take
        }
    int beautifulSubsets(vector<int> &nums, int k)
    {
        int n = nums.size();
        map<int,int> mp;
        int ans = getans(nums, k, mp, 0);
        return ans - 1;
    }
};