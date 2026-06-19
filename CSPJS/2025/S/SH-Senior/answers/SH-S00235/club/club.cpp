#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll t, n, a[N][4], x, f[N], s[N], m[N], y[4], res;
ll n1[3][N], tot[3];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		memset(a, 0, sizeof a);
		memset(s, 0, sizeof s);
		memset(f, 0, sizeof f);
		memset(m, 0, sizeof m);
		memset(y, 0, sizeof y);
		res = 0;
		cin >> n;
		x = n / 2;
		for(ll i = 1; i <= n; i++) {
			ll an;
		    for(ll j = 1; j <= 3; j++) {
		    	cin >> a[i][j];
		    	if(a[i][j] >= f[i]) {
		    		ll an = j;
		    		m[i] = a[i][j] - f[i];
		    		s[i] = f[i];
		    		f[i] = a[i][j];
				} else {
					if(a[i][j] >= s[i]) {
						m[i] = f[i] - a[i][j];
						s[i] = a[i][j];
					}
				}
			}
			res += f[i];
			y[an]++;
		    n1[an][++tot[an]] = m[i];
		}
		if(y[1] <= x && y[2] <= x && y[3] <= x) {
			cout << res << endl;
			continue;
		}
		if(y[1] > x) {
			sort(n1[1] + 1, n1[1] + 1 + tot[1]);
			for(ll i = 1; i <= tot[1] - x; i++) {
				res = res - n1[1][i];
			}
			cout << res << endl;
			continue;
		}
		if(y[2] > x) {
			sort(n1[2] + 1, n1[2] + 1 + tot[2]);
			for(ll i = 1; i <= tot[2] - x; i++) {
				res = res - n1[2][i];
			}
			cout << res << endl;
			continue;;
		}
		if(y[3] > x) {
			sort(n1[3] + 1, n1[3] + 1 + tot[3]);
			for(ll i = 1; i <= tot[3] - x; i++) {
				res = res - n1[3][i];
			}
			cout << res << endl;
			continue;
		}
	}
	return 0;
}
