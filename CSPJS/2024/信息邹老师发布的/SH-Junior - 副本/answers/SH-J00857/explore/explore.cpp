#include <bits/stdc++.h>
using namespace std;
typedef vector<string> forest;
int solve(int n, int m, int k, int x, int y, int d, forest a) {
	bool vst[1009][1009] = {};
	--x;
	--y;
	vst[x][y] = true;
	int ans = 1;
	for (int i = 0; i < k; ++i) {
		if (d == 0) {
			++y;
			if (!(0 <= x && x < n && 0 <= y && y < m) || a[x][y] == 'x') {
				d = 1;
				--y;
			} else {
				if (!vst[x][y]) ++ans;
				vst[x][y] = true;
			} continue;
		} if (d == 1) {
			++x;
			if (!(0 <= x && x < n && 0 <= y && y < m) || a[x][y] == 'x') {
				d = 2;
				--x;
			} else {
				if (!vst[x][y]) ++ans;
				vst[x][y] = true;
			} continue;
		} if (d == 2) {
			--y;
			if (!(0 <= x && x < n && 0 <= y && y < m) || a[x][y] == 'x') {
				d = 3;
				++y;
			} else {
				if (!vst[x][y]) ++ans;
				vst[x][y] = true;
			} continue;
		} if (d == 3) {
			--x;
			if (!(0 <= x && x < n && 0 <= y && y < m) || a[x][y] == 'x') {
				d = 0;
				++x;
			} else {
				if (!vst[x][y]) ++ans;
				vst[x][y] = true;
			} continue;
		}
	}
	return ans;
}
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin>>T;
	int n, m, k, x, y, d;
	forest a(1009, "");
	for (; T; --T) {
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for (int i = 0; i < n; ++i) cin>>a[i];
		cout<<solve(n, m, k, x, y, d, a)<<endl;
	}
	return 0;
}
