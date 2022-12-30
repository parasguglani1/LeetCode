
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
       // int ind= strstrhaystack,needle);
        int ind= haystack.find(needle);
        // cout<<ind;
        if (ind==string::npos)
        {
            
        return -1;
        }
    return ind;
    }
    
};