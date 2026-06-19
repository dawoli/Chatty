#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int t, n, ans, cnt[4];
bool table[3 * N];
pair<int, pair<int, int>> num[3 * N];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = cnt[1] = cnt[2] = cnt[3] = 0;
		for (int i = 1; i <= n; i++) table[i] = 0;
		for (int i = 1; i <= n; i++) {
			int x, y, z, mid;
			cin >> x >> y >> z;
			if ((x - y) * (x - z) <= 0) mid = x;
			else if ((y - x) * (y - z) <= 0) mid = y;
			else mid = z;
			ans += mid;
			num[i * 3 - 2] = {x - mid, {i, 1}};
			num[i * 3 - 1] = {y - mid, {i, 2}};
			num[i * 3] = {z - mid, {i, 3}};
		}
		sort(num + 1, num + 3 * n + 1);
		for (int i = n * 3; i >= 1; i--) {
			if (table[num[i].second.first] || cnt[num[i].second.second] == n / 2) continue;
			ans += num[i].first; 
			cnt[num[i].second.second]++;
			table[num[i].second.first] = 1;
		}
		cout << ans << endl;
	}
	return 0;
} 
