#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, ans, top, num, pos;
int a[N][5], maxn[N], minn[N], mid[N], d[N], maxn_pos[N], cnt[10], D[N];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		memset(a, 0, sizeof(a));
		memset(maxn, 0, sizeof(maxn));
		memset(minn, 0, sizeof(minn));
		memset(mid, 0, sizeof(mid));
		memset(d, 0, sizeof(d));
		memset(maxn_pos, 0, sizeof(maxn_pos));
		memset(cnt, 0, sizeof(cnt));
		memset(D, 0, sizeof(D));
		ans = 0, n = 0, top = 0, num = 0, pos = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
			maxn[i] = max(max(a[i][1], a[i][2]), a[i][3]);
			minn[i] = min(min(a[i][1], a[i][2]), a[i][3]);
			
			for(int x = 1; x <= 3; x++) {
				for(int y = 1; y <= 3; y++) {
					if(x == y) continue;
					if(a[i][x] == a[i][y]) mid[i] = a[i][x];
				}
			}
			for(int j = 1; j <= 3; j++) {
				if(a[i][j] != maxn[i] && a[i][j] != minn[i]) mid[i] = a[i][j];
				else if(a[i][j] == maxn[i]) {
					maxn_pos[i] = j;
					cnt[j]++;
				}
			}
			d[i] = maxn[i]-mid[i];
			ans += maxn[i];
		}
		for(int i = 1; i <= 3; i++) {
			if(cnt[i] > n/2) {
				pos = i;
				num = cnt[i]-n/2;
			}
		}
		if(pos == 0) cout << ans << "\n";
		else {
			for(int i = 1; i <= n; i++) {
				if(maxn_pos[i] == pos) D[++top] = d[i];
			}
			sort(D+1, D+top+1);
			for(int i = 1; i <= num; i++) {
				ans -= D[i];
			}
			cout << ans <<"\n";
		}
	}
	return 0;
} 
