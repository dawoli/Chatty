#include<bits/stdc++.h>
using namespace std;
#define int long long

string s;
vector<int> v;

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(nullptr), cout.tie(nullptr) -> sync_with_stdio(false);

	cin >> s;

	for(char ch : s) {
		if('0' <= ch && ch <= '9')
			v.push_back(ch - '0');
	}
	sort(v.begin(), v.end(), greater<int>());

	for(int val : v) cout << val;
	cout << "\n";
	return 0;
}
