#include<bits/stdc++.h>
using namespace std;
#define N 100010
int cnt[5], c[N], n, a[N][3];
int calc(int gro) {
	vector<int>g;
	for(int i = 1; i <= n; i++) {
		if(c[i] != gro) continue;
		int mx = max(a[i][1], max(a[i][2], a[i][3]));
		int mn = 1e9;
		for(int j = 1; j <= 3; j++) {
			if(j == gro) continue;
			mn = min(mn, mx - a[i][j]);
		}
		g.push_back(mn);
	}
	sort(g.begin(), g.end());
	int tot = 0;
	for(int i = 0; i < cnt[gro] - n / 2; i++) tot += g[i];
	return tot;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int ans = 0;
		cnt[1] = 0; cnt[2] = 0; cnt[3] = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			int mx = max(a[i][1], max(a[i][2], a[i][3]));
			ans += mx;
			if(a[i][1] == mx) {
				cnt[1]++;
				c[i] = 1;
			}
			else if(a[i][2] == mx) {
				cnt[2]++;
				c[i] = 2;
			}
			else {
				cnt[3]++;
				c[i] = 3;
			}
		}
		if(cnt[1] > n / 2) {
			ans -= calc(1);
		}
		if(cnt[2] > n / 2) {
			ans -= calc(2);
		}
		if(cnt[3] > n / 2) {
			ans -= calc(3);
		}
		printf("%d\n", ans);
	}
}
