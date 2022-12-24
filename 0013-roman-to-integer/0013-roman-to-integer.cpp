#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
  int romanToInt(string s)
  {
	int num[s.length()];
	int value[] = {1, 5, 10, 50, 100, 500, 1000};
	char C[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

	map<char, int> mp;
	for (int i = 0; i < 7; i++)
	{
	  mp[C[i]] = value[i];
	}

	int ans = 0;

	for (int i = 0; i < s.length(); i++)
	{
	  num[i] = mp[s[i]];
	}

	for (int i = 0; i < s.length() - 1; i++)
	{
	  if (num[i + 1] > num[i])
	  {
		num[i] = num[i + 1] - num[i];
		num[i + 1] = 0;
		i += 1;
	  }
	}
	for (int i = 0; i < s.length(); i++)
	{
	  ans += num[i];
	}
	return ans;
  }
};

