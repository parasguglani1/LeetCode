class Solution
{
    public:
        string addBinary(string a, string b)
        {
        string res;
        int carry = 0, i = a.size(), j = b.size();
        while(i > 0 || j > 0 || carry == 1)
        {
            if (i > 0) carry += a[--i] - '0';
            if (j > 0) carry += b[--j] - '0';
            res += char(carry % 2 + '0');
            carry /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
                
        }
};