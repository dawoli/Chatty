#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200001;
int T, n, a[N], stat[N];
namespace c1 {
	ll mx = 0;
	void dfs (int x) {
		if (x == n+1) {
			int sc[2] = {-1, -1};
			ll ans = 0;
			for (int i = 1; i <= n; i++) {
				if (sc[stat[i]] != -1 && a[i] == a[sc[stat[i]]])
					ans += 1ll*a[i];
				sc[stat[i]] = i;
			}
			mx = max(mx, ans);
			return;
		}
		stat[x] = 0;
		dfs(x+1);
		stat[x] = 1;
		dfs(x+1);
	}
	void solve() {
		mx = 0;
		dfs(1);
		printf("%lld\n", mx);
	}
}
namespace ca10 {
	vector<int> pv[11];
	ll mx = 0;
	bool check() {
		for (int i = 1; i <= n; i++)
			if (a[i] > 10)
				return false;
		return true;
	}
	void dfs (int x) {
		if (x == 11) {
			int sc[2] = {-1, -1};
			ll ans = 0;
			for (int i = 1; i <= n; i++) {
				if (sc[stat[a[i]]] != -1 && a[i] == a[sc[stat[a[i]]]])
					ans += 1ll*a[i];
				sc[stat[a[i]]] = i;
			}
			mx = max(mx, ans);
			return;
		}
		stat[x] = 0;
		dfs(x+1);
		stat[x] = 1;
		dfs(x+1);
	}
	void solve() {
		mx = 0;
		dfs(1);
		printf("%lld\n", mx);
	}
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if (n <= 15)
			c1::solve();
		else if (ca10::check())
			ca10::solve();
	}
	return 0;
}
