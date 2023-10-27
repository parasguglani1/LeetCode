class Solution {
public:
   string longestPalindrome(string s) {
	const int n = s.size();
	if(n==0) return "";
	int dp[n][n], maxlen =1 , left=0;// maxlen = 1 when only one word
	memset(dp,0,n*n*sizeof(int));
	for(int i=0;i<n;++i){
		dp[i][i] = 1;
		for(int j=0;j<i;++j){
			dp[j][i] = (s[j]==s[i]  && (i-j< 2 || dp[j+1][i-1]));
			if(dp[j][i] && maxlen < i-j+1){
				left = j;
				maxlen = i-j+1;
			}
		}
	}
	return s.substr(left,maxlen);
}

};