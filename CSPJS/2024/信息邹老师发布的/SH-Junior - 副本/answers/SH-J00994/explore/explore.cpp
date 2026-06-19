#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dx[4] = {0, 1, 0, -1};
ll dy[4] = {1, 0, -1, 0};
ll T, n, m, k, x, y, d;
char a[3009][3009];
set<pair<ll,ll>> st;

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> n >> m >> k >> x >> y >> d;
		memset(a, 0, sizeof(a));
		for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) cin >> a[i][j];
		st.clear();
		for(ll i = 1; i <= k; i++) {
			st.insert(make_pair(x, y));
			ll nx = x+dx[d], ny = y+dy[d];
			if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x') (d += 1) %= 4;
			else {
				x = nx;
				y = ny;
			}
		}
		st.insert(make_pair(x, y));
		cout << st.size() << endl;
	}
	return 0;
}

