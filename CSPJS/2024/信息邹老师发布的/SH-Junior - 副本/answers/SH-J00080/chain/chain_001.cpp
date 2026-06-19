#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int res = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res;
}

const int N = 2e5 + 10, R = 110;
int T, n, k, q, l[N], d[N];
vector<int> s[N];
vector<bool> ok[N];
int vis[N];
int pos[N], cnt[N];
struct Query {
	int c, id;
};
vector<Query> que[R];
bool ans[N];

signed main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	T = read();
	while (T--) {
		n = read(), k = read(), q = read();
		for (int i = 1; i <= n; ++i) {
			vector<int> ().swap(s[i]);
			l[i] = read();
			ok[i].assign(l[i], 0);
			for (int j = 0, val; j < l[i]; ++j) {
				val = read();
				s[i].push_back(val);
			}
			for (int j = 0; j < l[i]; ++j)
				if (s[i][j] == 1) ok[i][j] = true;
		}
		for (int i = 1; i <= 100; ++i)
			vector<Query> ().swap(que[i]);
		for (int i = 1, r, c; i <= q; ++i) {
			r = read(), c = read();
			que[r].push_back((Query){c, i});
		}
		for (int t = 1; t <= 100; ++t) {
			memset(vis, 0, sizeof(vis));
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j < l[i]; ++j) d[j] = 0;
				for (int j = 0; j + 1 < l[i]; ++j)
					if (ok[i][j]) {
						++d[j + 1];
						if (j + k < l[i]) --d[j + k];
					} 
				int sum = 0;
				for (int j = 0; j < l[i]; ++j) {
					sum += d[j];
					if (sum) ++vis[s[i][j]];
				}
			}
			for (int i = 0; i < que[t].size(); ++i)
				ans[que[t][i].id] = vis[que[t][i].c];
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j < l[i]; ++j) d[j] = 0;
				for (int j = 0; j + 1 < l[i]; ++j)
					if (ok[i][j]) {
						++d[j + 1];
						if (j + k < l[i]) --d[j + k];
					} 
				int sum = 0;
				for (int j = 0; j < l[i]; ++j) {
					sum += d[j];
					if (sum) --vis[s[i][j]];
				}
				for (int j = 0; j < l[i]; ++j)
					ok[i][j] = vis[s[i][j]];
				sum = 0;
				for (int j = 0; j < l[i]; ++j) {
					sum += d[j];
					if (sum) ++vis[s[i][j]];
				}
			}
//			if (t > 4) continue;
//			cout << "r = " << t << " : " << endl;
//			for (int i = 1; i <= n; ++i, cout << endl)
//				for (int j = 0; j < l[i]; ++j) cout << ok[i][j] << " ";
		}
		for (int i = 1; i <= q; ++i) putchar(ans[i] + '0'), puts("");
	}
	return 0;
}
