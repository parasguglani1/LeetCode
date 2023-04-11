class Solution
{
    public:
        bool isPossible(vector<int> &heights, int bricks, int ladders, int mid)
        {
            vector<int> diff;
            for (int i = 1; i <= mid; i++)
            {
                if (heights[i] > heights[i - 1])
                    diff.push_back(heights[i] - heights[i - 1]);
            }
            sort(diff.begin(), diff.end(), greater<int> ());
            for (int i = ladders; i < diff.size(); i++)
            {
                if (bricks < diff[i]) return false;
                bricks -= diff[i];
            }
            return true;
        }
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {

        int s = 0, e = heights.size() - 1;
        int ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (isPossible(heights, bricks, ladders, mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
};