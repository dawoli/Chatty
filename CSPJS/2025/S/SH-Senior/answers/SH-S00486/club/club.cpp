#include <bits/stdc++.h>
#define int long long
#define For(i, a, b) for (int i = (a); i <= (b); i ++)
#define foR(i, a, b) for (int i = (a); i >= (b); i --)
using namespace std;
int n;
int a[100005][4];
vector <int> v[4];
signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	int _;
	scanf ("%lld", &_);
	while (_ --) {
		v[1].clear ();
		v[2].clear ();
		v[3].clear ();
		int ans = 0, s1 = 0, s2 = 0, s3 = 0;
		scanf ("%lld", &n);
		For (i, 1, n) {
			scanf ("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
			int mx = max (max (a[i][1], a[i][2]), a[i][3]);
			if ( (a[i][1] == mx) + (a[i][2] == mx) + (a[i][3] == mx) == 1) {
				int se = 0;
				if (a[i][1] != mx) se = max (se, a[i][1]);
				if (a[i][2] != mx) se = max (se, a[i][2]);
				if (a[i][3] != mx) se = max (se, a[i][3]);
				if (a[i][1] == mx) {
					++ s1;
					v[1].push_back (se - mx);
				}
				if (a[i][2] == mx) {
					++ s2;
					v[2].push_back (se - mx);
				}
				if (a[i][3] == mx) {
					++ s3;
					v[3].push_back (se - mx);
				}
			}
			ans += mx;
		}
		sort (v[1].begin (), v[1].end () );
		sort (v[2].begin (), v[2].end () );
		sort (v[3].begin (), v[3].end () );
		while (s1 > n / 2) {
			-- s1;
			ans += v[1].back ();
			v[1].pop_back ();
		}
		while (s2 > n / 2) {
			-- s2;
			ans += v[2].back ();
			v[2].pop_back ();
		}
		while (s3 > n / 2) {
			-- s3;
			ans += v[3].back ();
			v[3].pop_back ();
		}
		cout << ans << '\n';
	}
	return 0;
}
