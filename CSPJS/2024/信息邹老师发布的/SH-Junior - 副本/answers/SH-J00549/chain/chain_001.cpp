#include<bits/stdc++.h>
using namespace std;

int t;
int n, k, q, x, r, c, flag;
int l[200002];
vector<int> s[200002];
vector<pair<int, int> > g[200002];

int dfs(int d, int x, int y) {
	int yy;
	if (d == r) {
		for (int i=2; i<=k; i++) {
			yy = y+i-1;
			if (s[x][yy] == c) {
				return 1;
			}
		}
		return 0;
	}
	for (int i=2; i<=k; i++) {
		yy = y+i-1;
		for (auto &j:g[s[x][yy]]) {
		    if (j.first == x) continue;
                //cout << j.first << ' ' << j.second << '\n';
			if (dfs(d+1, j.first, j.second)) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);

	cin >> t;
	while (t--) {
		for (int i=1; i<=200000; i++) {
			if (!g[i].empty()) g[i].clear();
		}

		cin >> n >> k >> q;
		for (int i=1; i<=n; i++) {
			s[i].clear();
			cin >> l[i];
			for (int j=0; j<l[i]; j++) {
				cin >> x;
				s[i].push_back(x);
				g[x].push_back(make_pair(i, j));
			}
		}
		for (int i=1; i<=q; i++) {
			flag = 0;
			cin >> r >> c;
			for (int j=1; j<=n; j++) {
				if (dfs(1, j, 0)) {
					cout << 1 << '\n';
					flag = 1;
					break;
				}
			}
			if (!flag) cout << 0 << '\n';
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}


