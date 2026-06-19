#include <iostream>
#include <algorithm>
using namespace std; 
int t, n, a[100005][8];
int len, num[100005], cnt[8], d[100005], ans, tgt;
int solve() {
	cin >> n;
	ans = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
			num[i] = 1;
		else if (a[i][2] >= a[i][3] && a[i][2] >= a[i][1])
			num[i] = 2;
		else num[i] = 3;
		++cnt[num[i]];
		ans += a[i][num[i]];
	}
	int x, y, z;
	if (cnt[1] > n / 2) {
		x = 1; y = 2; z = 3;
	}
	else if (cnt[2] > n / 2) {
		x = 2; y = 3; z = 1;
	}
	else {
		x = 3; y = 1; z = 2;
	}
	len = 0;
	for (int i = 1; i <= n; ++i)
		if (num[i] == x)
			d[++len] = min(a[i][x] - a[i][y], 
				a[i][x] - a[i][z]);
	sort(d + 1, d + len + 1);
	tgt = cnt[x] - n / 2;
	for (int i = 1; i <= tgt; ++i)
		ans -= d[i];
	return ans;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--)
		cout << solve() << endl;
	return 0;
}
