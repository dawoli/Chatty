#include <bits/stdc++.h>
using namespace std;
const int N = 200005, L = 5000005, base = 13331, mod = 998244353;
int n, q, tb, ans[N], pl[N], pa[N], sl[N], sa[N];
vector<int> pb[N], sb[N];
string s[N][2], t[N][2];
struct hash {
	int h1, h2, id;
	bool operator< (const hash &o) const {
		if (h1 != o.h1) return h1 < o.h1;
		return h2 < o.h2;
	}
} a[N], b[N];
int main() {
	//why getting to a terrible end
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
		int x = s[i][0].size(), l, r;
		for (l = 0; l < x; l++) if (s[i][0][l] != s[i][1][l]) break;
		for (r = x - 1; r >= 0; r--) if (s[i][0][r] != s[i][1][r]) break;
		for (int j = l; j <= r; j++) {
			a[i].h1 = (1ll * a[i].h1 * base + s[i][0][j] - 'a') % mod;
			a[i].h2 = (1ll * a[i].h2 * base + s[i][1][j] - 'a') % mod;
		}
		pl[i] = l, sl[i] = x - r - 1;
		for (int j = l - 1; j >= 0; j--) pa[i] = (1ll * pa[i] * base + s[i][0][j] - 'a') % mod;
		for (int j = r + 1; j < x; j++) sa[i] = (1ll * sa[i] * base + s[i][1][j] - 'a') % mod;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= q; i++) {
		cin >> t[i][0] >> t[i][1];
		if (t[i][0].size() != t[i][1].size()) {
			ans[i] = 0;
			continue;
		}
		int x = t[i][0].size(), l, r;
		for (l = 0; l < x; l++) if (t[i][0][l] != t[i][1][l]) break;
		for (r = x - 1; r >= 0; r--) if (t[i][0][r] != t[i][1][r]) break;
		++tb;
		for (int j = l; j <= r; j++) {
			b[tb].h1 = (1ll * b[tb].h1 * base + t[i][0][j] - 'a') % mod;
			b[tb].h2 = (1ll * b[tb].h2 * base + t[i][1][j] - 'a') % mod;
		}
		pb[i].resize(l + 1);
		sb[i].resize(x - r);
		for (int j = 1; j <= l; j++) pb[i][j] = (1ll * pb[i][j - 1] * base + t[i][0][l - j] - 'a') % mod;
		for (int j = 1; j < x - r; j++) sb[i][j] = (1ll * sb[i][j - 1] * base + t[i][1][j + r] - 'a') % mod;
		b[tb].id = i;
	}
	sort(b + 1, b + tb + 1);
	for (int i = 1; i <= tb; i++) {
		int v = upper_bound(a + 1, a + n + 1, b[i]) - a - 1;
		int u = lower_bound(a + 1, a + n + 1, b[i]) - a;
		if (u > v) {
			ans[b[i].id] = 0;
			continue;
		}
		int cnt = 0;
		for (int j = u; j <= v; j++) if (pb[i][pl[j]] == pa[j] && sb[i][sl[j]] == sa[j]) ++cnt;
		ans[b[i].id] = cnt;
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
