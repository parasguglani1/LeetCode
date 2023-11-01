class Solution
{
    public:
        void getpermute(vector<vector<int>>&ans,vector< int >&temp, vector< int > nums,vector<int> freq)
        {
            if (temp.size() == nums.size())
            {
                ans.push_back(temp);
                return;
            }

            for (int t = 0; t < nums.size(); t++)
            {
                if (!freq[t])
                    {
                        temp.push_back(nums[t]);
                    freq[t]=1;
                        getpermute(ans, temp, nums,freq);
                    freq[t]=0;
                    temp.pop_back();
                    }
                }
            }
            vector<vector < int>> permute(vector<int> &nums)
            {
                vector<vector<int>>ans;
                vector<int> temp, freq(nums.size(), 0);
                getpermute(ans, temp, nums, freq);
                return ans;
            }
        };