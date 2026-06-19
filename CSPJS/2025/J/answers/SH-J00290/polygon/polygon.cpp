#include <bits/stdc++.h>
using namespace std;
long long ans;
int n, tem = 3;
vector<int> lens;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1, num; i <= n; ++i) {
		cin >> num;
		lens.push_back(num);
	}
	sort(lens.begin(), lens.end());
	if (lens.size() >= 3 && lens[0] + lens[1] > lens[2]) ans = 1;
	cout << ans % 998244353;
	return 0;
} 
