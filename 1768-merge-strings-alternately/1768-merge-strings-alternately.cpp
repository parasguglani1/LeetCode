class Solution
{
    public:
        string mergeAlternately(string word1, string word2)
        {
            int n1 = word1.size();
            int n2 = word2.size();
           	// if(n1 < n2)
           	// {
           	//     swap(n1,n2);
           	//     swap(word1,word2);
           	// }
            int i = 0, j = 0, k = 0;
            string ans = "";
            while (j < n2 && i < n1)
            {
                if (k % 2)
                {
                    ans += word2[j];
                    j++;
                }
                else
                {
                    ans += word1[i];
                    i++;
                }
                k++;
            }
            while (i < n1)
            {
                ans += word1[i];
                i++;
            }
            while (j < n2)
            {
                ans += word2[j];
            j++;
        }
    return ans;
}
};