#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;
ll n, a [4] [N];
ll maxx (ll a, ll b, ll c) {
	ll tmp = max (a, max (b, c));
	if (tmp == a) return 1;
	else if (tmp == b) return 2;
	else return 3;
}
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	int T; cin >> T;
	while (T --) {
		scanf ("%lld", &n);
		for (int i = 1; i <= n; i ++)
			scanf ("%lld %lld %lld", & a [1] [i], & a [2] [i], & a [3] [i]);
		vector <int> cnt [4];
		for (int i = 1; i <= n; i ++)
			cnt [maxx (a [1] [i], a [2] [i], a [3] [i])].push_back (i);
		ll tmp = max (cnt [1].size (), max (cnt [2].size (), cnt [3].size ()));
		ll ans = 0;
		for (int i = 1; i <= n; i ++)
			ans += max (a [1] [i], max (a [2] [i], a [3] [i]));
		if (tmp <= n / 2) {
			cout << ans << endl;
			continue;
		}
		ll cur = maxx (cnt [1].size (), cnt [2].size (), cnt [3].size ());
		vector <ll> sum;
		for (ll k = 0; k < cnt [cur].size (); k ++) {
			ll tmp = -1e18, i = cnt [cur] [k];
			for (int j = 1; j <= 3; j ++)
				if (j != cur)
					tmp  = max (a [j] [i] - a [cur] [i], tmp); 
			sum.push_back (tmp);
		}
		sort (sum.begin (), sum.end (), greater <int> ());
		for (int i = 0; i < tmp - n / 2; i ++)
			ans += sum [i];
		cout << ans << endl;
	}
}
