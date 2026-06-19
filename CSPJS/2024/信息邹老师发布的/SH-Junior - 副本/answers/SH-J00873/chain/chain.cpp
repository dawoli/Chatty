#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k, q;
int l[200005];
vector<int> S[200005];
int r, c;
int RR1[200005], RR2[200005];
int *R1, *R2;
set<int> C[200005];
vector<pair<int, int> > P[200005];
bool s3 = false;

void solve1() {
	// 1
	for (int i = 1; i <= n; i++) {
		int x = 0;
		for (int j = 0; j < l[i]; j++) {
			if (x) {
				x--;
				if (S[i][j] == c) {
					cout << "1\n";
					return;
				}
			}
			if (S[i][j] == 1) {
				x = k - 1;
			}
		}
	}
	cout << "0\n";
}

bool solve2_dfs(int u, int p, int r, int c) {
	if (r == 0) return u == c;
	for (int i = 1; i <= n; i++) {
		if (i == p) continue;
		int x = 0;
		for (int j = 0; j < l[i]; j++) {
			if (x) {
				x--;
				if (solve2_dfs(S[i][j], i, r - 1, c)) {
					return true;
				}
			}
			if (S[i][j] == u) {
				x = k - 1;
			}
		}
	}
	return false;
}

void solve2() {
	// 2 3
	cout << solve2_dfs(1, -1, r, c) << "\n";
}

void solve3() {
	// 7 8
	R1 = RR1, R2 = RR2;
	if (!s3) {
		for (int i = 1; i <= n; i++) {
			map<int, int> M;
			for (int j = 0; j < l[i]; j++) {
				for (auto x : C[i]) {
					if (M[x]) {
						M[x]--;
						P[x].push_back({S[i][j], i});
					}
					if (S[i][j] == x) {
						M[x] = k - 1;
					}
				}
			}
		}
		s3 = true;
	}
	for (int i : C[0]) {
		R1[i] = 0;
	}
	R1[1] = -1;
	while (r--) {
		for (int i : C[0]) {
			R2[i] = 0;
		}
		for (int i : C[0]) {
			if (!R1[i]) continue;
			for (auto x : P[i]) {
				if (x.second == R1[i]) continue;
				if (R2[x.first] && R2[x.first] != i) R2[x.first] = -1;
				else R2[x.first] = i;
			}
		}
		swap(R1, R2);
	}
	if (R1[c]) cout << "1\n";
	else cout << "0\n";
}

int main() {
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> k >> q;
		int sum = 0;
		C[0].clear();
		for (int i = 1; i <= n; i++) {
			cin >> l[i];
			sum += l[i];
			S[i].clear();
			C[i].clear();
			for (int j = 1; j <= l[i]; j++) {
				int x;
				cin >> x;
				S[i].push_back(x);
				C[i].insert(x);
				C[0].insert(x);
			}
		}
		while (q--) {
			cin >> r >> c;
			if (n <= 1000 && r <= 1 && sum <= 2000 && q <= 1000) {
				solve1();
			} else if (n <= 10 && r <= 5  && sum <= 20 && q <= 100) {
				solve2();
			} else {
				solve3();
			}
		}
	}
	return 0;
}

