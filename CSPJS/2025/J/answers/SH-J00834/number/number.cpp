#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	vector<int> num;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			num.push_back(s[i] - '0');
		}
	}
	sort(num.begin(), num.end(), greater<int>());
	for(int i = 0; i < num.size(); i++) {
		cout << num[i];
	}
	return 0;
}
