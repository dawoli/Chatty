#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	// cout << s << endl;
	for (int i = 0; i < s.size(); i ++)
	{
		if (isdigit(s[i]))
		{
			nums.push_back(s[i] - '0');
			// cout << s[i] << endl;
		}
	}
	sort(nums.begin(), nums.end(), greater<int>());
	if (nums[0] == 0)
	{
		puts("0");
	}
	else
	{
		for (int i = 0; i < nums.size(); i ++)
		{
			cout << nums[i];
		}
		cout << endl;
	}
	return 0;
}
