#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 10;
ll T, n, k, Q, r, c, sz[N];
vector<ll> S[N];
vector<pair<ll, ll> > G[N];
struct Node {
	ll lun, val, per;
};
vector<ll> ans[N];

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld %lld %lld", &n, &k, &Q);
		for (int i = 1; i <= n; i ++) {
			S[i].clear();
			G[i].clear();
			ans[i].clear();
		}
		for (int i = 1; i <= n; i ++) {
			scanf("%lld", &sz[i]); ll si;
			for (int j = 1; j <= sz[i]; j ++) {
				scanf("%lld", &si);
				S[i].push_back(si);
			}
		}
		if (n <= 10) {
			for (int i = 1; i <= n; i ++) {
				for (unsigned a = 0; a < S[i].size(); a ++) {
					for (unsigned b = a + 1; b - a + 1 <= k && b < S[i].size(); b ++) {
						G[S[i][a]].push_back({S[i][b], i});
					}
				}
			}
//			// {lun, value, lst_used_person}
			queue<Node> q;
			q.push(Node{1, 1, 0});
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				if (cur.lun > 11) continue;
				int v = cur.val;
				for (auto it: G[v]) {
					if (it.second != cur.per) {
						ans[it.first].push_back(cur.lun);
						q.push(Node{cur.lun + 1, it.first, it.second});
					}
				}
			}
		}
		while (Q--) {
			scanf("%lld %lld", &r, &c);
			if (r == 1) {
				bool ok = false;
				for (int i = 1; i <= n; i ++) if (!ok) {
					for (int j = 0; j < sz[i]; j ++) if (!ok) {
						if (S[i][j] == 1) {
							for (int len = 2; len <= k
							&& j + len - 1 < sz[i]; len ++) {
								if (S[i][j + len - 1] == c) {
									ok = true; break;
								}
							}
						}
					}
				}
				if (ok) printf("1\n");
				else printf("0\n");
				continue;
			}
			if (ans[c].empty()) {
				printf("0\n");
			} else {
				if (*lower_bound(ans[c].begin(), ans[c].end(), r) == r) {
					printf("1\n");
				} else {
					printf("0\n");
				}
			}
		}
	}
	return 0;
}
