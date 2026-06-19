#include <bits/stdc++.h>
#define For(i, a, b) for (int i = (a); i <= (b); i ++)
#define foR(i, a, b) for (int i = (a); i >= (b); i --)
#define int long long
using namespace std;
int n;
int a[100005], b[100005];
signed main () {
	freopen ("duel.in", "r", stdin);
	freopen ("duel.out", "w", stdout);
	cin >> n;
	For (i, 1, n) {
		cin >> a[i];
		++ b[a[i] ];
	}
	int ans = n, tmp = 0;
	For (i, 1, 100000) {
		int x = min (b[i], tmp);
		ans -= x;
		tmp += b[i] - x;
	}
	cout << ans;
	return 0;
}
