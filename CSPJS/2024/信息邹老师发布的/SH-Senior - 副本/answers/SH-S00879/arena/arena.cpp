#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int A[100005], B[100005], C[100005], E[100005];
string D[50];
set<ll> wins;
bool F;

void calc(int n, bool c) {
	vector<int> A, B;
	for (int i = 1; i <= n; i++) {
		A.push_back(i);
	}
	int cnt = 1;
//	cout << "players: ";
//	for (auto i : A) {
//		cout << i << " : " << E[i] << "\n";
//	}
//	cout << endl;
	while (A.size() > 1) {
		for (int i = 0; i < A.size() / 2; i++) {
			// 2i, 2i+1
			if ((D[cnt][i] == '1' && E[A[2 * i + 1]] >= cnt) || (D[cnt][i] == '0' && E[A[2 * i]] < cnt)) {
				// 2i+1 wins
				B.push_back(A[2 * i + 1]);
				if (c && A.size() == 2) {
					F = true;
					return;
				}
			} else {
				B.push_back(A[2 * i]);
				if (c && A.size() == 2) {
					wins.insert(A[0]);
					return;
				}
			}
		}
//		cout << "winner: ";
//		for (auto x : B) {
//			cout << x << " ";
//		}
//		cout << endl;
		swap(A, B);
		B.clear();
		cnt++;
	}
	wins.insert(A[0]);
}

void dfs(int i, int n) {
	if (i == n) {
		return calc(n, false);
	}
	for (int j = 0; j <= 8; j++) {
		E[i + 1] = j;
		dfs(i + 1, n);
	}
}

int main() {
	freopen("arena3.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> C[i];
	}
	for (int i = 1; (1 << i - 1) < n; i++) {
		cin >> D[i];
		for (auto j : D[i]) {
			if (j == '1') F = true;
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int X[4];
		for (int i = 0; i < 4; i++) {
			cin >> X[i];
		}
		for (int i = 1; i <= n; i++) {
			B[i] = A[i] ^ X[i % 4];
		}
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			if (n <= 8 && m <= 8) {
				for (int j = 1; j <= C[i]; j++) {
					E[j] = B[j];
				}
				wins.clear();
				int x = 1;
				while (x < C[i]) x <<= 1;
				dfs(C[i], x);
				int sum = 0;
				for (auto j : wins) {
					sum += j;
				}
				ans ^= i * sum;
			} else {
				int x = C[i];
				while (x % 2 == 0) x /= 2;
				if (x == 1) {
					// A
					for (int j = 1; j <= C[i]; j++) {
						E[j] = B[j];
					}
					wins.clear();
					calc(C[i], false);
					for (auto j : wins) { // only 1 item
						ans ^= i * j;
					}
				} else if (!F) {
					// B
					for (int j = 1; j <= C[i]; j++) {
						E[j] = B[j];
					}
					wins.clear();
					int x = 1;
					while (x < C[i]) x <<= 1;
					calc(x, true);
					if (F) {
						for (int j = C[i] + 1; j <= x; j++) {
							wins.insert(j);
						}
						F = false;
					}
					ll sum = 0;
					for (auto j : wins) {
						sum += j;
					}
					ans ^= i * sum;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

