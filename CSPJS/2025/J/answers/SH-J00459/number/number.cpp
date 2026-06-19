#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<int> nums;
	for (char c : s)
		if (isdigit(c))
			nums.push_back(c - '0');
	sort(nums.begin(), nums.end(), greater<int>());
	if (nums[0] == 0) {
		cout << 0;
		return 0;
	}
	for (int x : nums)
		cout << x;
	return 0;
}
