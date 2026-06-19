#include <bits/stdc++.h>
using namespace std;
#define N 100010
int t, n, d[N];
struct member {
	int a1, a2, a3, t, m;
} a[N];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		int cnt = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			a[i].m = max(a[i].a1, max(a[i].a2, a[i].a3));
			if(a[i].m == a[i].a1) cnt1++, a[i].t = 1;
			else if(a[i].m == a[i].a2) cnt2++, a[i].t = 2;
			else cnt3++, a[i].t = 3;
			ans += a[i].m;
		}
		int maxx = max(cnt1, max(cnt2, cnt3)), de;
		if(maxx > n / 2) {
			if(maxx == cnt1) de = 1;
			else if(maxx == cnt2) de = 2;
			else de = 3;
			for(int i = 1; i <= n; i++)
				if(a[i].t == de)
					d[++cnt] = a[i].m * 2 + min(a[i].a1, min(a[i].a2, a[i].a3)) - a[i].a1 - a[i].a2 - a[i].a3;
			sort(d + 1, d + cnt + 1);
			for(int i = 1; i <= cnt; i++) {
				ans -= d[i], maxx--;
				if(maxx <= n / 2) break;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
