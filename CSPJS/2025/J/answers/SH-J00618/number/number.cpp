#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<int> nums;
	for (long long i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			nums.push_back(s[i] - '0'); 
		}
	}
	sort(nums.begin(), nums.end(), greater<int>());
	for (long long i = 0; i < nums.size(); i++) {
		cout << nums[i];
	}
} 
