// /**
//  *// This is the MountainArray's API interface.
//  *// You should not implement it, or speculate about its implementation
//  *class MountainArray {
//  *  public:
//  *    int get(int index);
//  *    int length();
//  *};
//  */

class Solution
{
    public:
        int findInMountainArray(int t, MountainArray &arr)
        {
            int l = 0, m, r = arr.length() - 1;
            int peakIndex;
            while (l <= r)
            {
                m = l + (r - l) / 2;
                if (arr.get(m) > arr.get(m + 1))
                {
                    peakIndex = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
           	//searching in left part of peak
            l = 0, r = peakIndex;
            while (l <= r)
            {
                m = l + (r - l) / 2;
                if (arr.get(m) == t)
                    return m;
                else if (arr.get(m) > t)
                    r = m - 1;
                else
                    l = m + 1;
            }
           	//searching in right part of peak
            l = peakIndex + 1, r = arr.length() - 1;
            while (l <= r)
            {
                m = l + (r - l) / 2;
                if (arr.get(m) == t)
                    return m;
                else if (arr.get(m) > t)
                    l = m + 1;
                else
                    r = m - 1;
            }
            return -1;
        }
};