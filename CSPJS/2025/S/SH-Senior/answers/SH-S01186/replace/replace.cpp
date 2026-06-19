#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q, len, ans;
bool flag[2003][2003];
string a[N], b[N], x, y;

void solve(string cx, string cy, int l, int r) {
	if(flag[l][r]) return;
	for(int i = 1; i <= n; i++) {
		if(cx.size() != a[i].size()) continue;
		if(cx == a[i] && cy == b[i]) ans++;
	}
	flag[l][r] = 1;
	if(r < len - 1) solve(cx + x[r + 1], cy + y[r + 1], l, r + 1);
	if(l > 0) solve(x[l - 1] + cx, y[l - 1] + cy, l - 1, r);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	while(q--) {
		ans = 0;
		memset(flag, 0, sizeof flag);
		cin >> x >> y;
		len = x.size();
		int l = 0, r = len - 1;
		while(x[l] == y[l] && l < len - 1) l++;
		while(x[r] == y[r] && r > 0) r--;
		if(l > r) {
			l = 0, r = len - 1;
		}
		string cx = "", cy = "";
		for(int i = l; i <= r; i++) cx += x[i], cy += y[i];
		solve(cx, cy, l, r);
		cout << ans << endl;
	}
}
