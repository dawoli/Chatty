#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
struct qwq {
	int a, b, c;
} a[100005];
int fp[4][100005], sp[4][100005], cntf[4], cnts[4];
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		cntf[1] = cntf[2] = cntf[3] = cnts[1] = cnts[2] = cnts[3] = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			int MP = max(a[i].a, max(a[i].b, a[i].c));
			int k = 0;
			if(MP == a[i].a) {
				fp[1][++cntf[1]] = a[i].a;
				a[i].a = -1;
				k = 1;
			}
			else if(MP == a[i].b) {
				fp[2][++cntf[2]] = a[i].b;
				a[i].b = -1;
				k = 2;
			}
			else {
				fp[3][++cntf[3]] = a[i].c;
				a[i].c = -1;
				k = 3;
			}
			MP = max(a[i].a, max(a[i].b, a[i].c));
			sp[k][++cnts[k]] = fp[k][cntf[k]] - MP;
		}
		int ans = 0;
		for(int i = 1; i <= cntf[1]; ++i) {
			ans += fp[1][i];
		}
		for(int i = 1; i <= cntf[2]; ++i) {
			ans += fp[2][i];
		}
		for(int i = 1; i <= cntf[3]; ++i) {
			ans += fp[3][i];
		}
		for(int i = 1; i <= 3; ++i) {
			if(cntf[i] > n / 2) {
				sort(sp[i] + 1, sp[i] + cnts[i] + 1);
				for(int j = 1; j <= cntf[i] - n / 2; ++j) {
					ans -= sp[i][j];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}