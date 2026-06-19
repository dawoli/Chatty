#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N];
int n, k, ans;
void search(int st, int cnt) {
	int val = 0;
	for (int i = st; i < n; i++) {
		val ^= a[i];
		if (val == k) {
			if (cnt + 1 > ans) ans = cnt + 1;
			if (i < n - 1) search(i + 1, cnt + 1);
		} else if (i < n - 1) {
			search(i + 1, cnt);
		}
	}
}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool sp = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] != 1 && a[i] != 0) sp = false;
	}
	if (sp) {
		int zeros = 0, ones = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) zeros++;
			else if (a[i] == 1) ones++;
		}
		if (k == 0) cout << zeros + ones / 2;
		else if (k == 1) cout << ones;
		return 0;
	}
	for (int i = 0; i < n; i++)
		search(i, 0);
	cout << ans;
	return 0;
}
