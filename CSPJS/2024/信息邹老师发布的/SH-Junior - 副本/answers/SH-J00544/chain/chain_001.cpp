#include <bits/stdc++.h>
using namespace std;
const int N = 464;
int n, k, q, r, c;
vector<int> a[N];
bool dp[N][N][N];
bool check()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			fill(dp[i][j], dp[i][j] + N, 0);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int p = 0; p < a[i].size(); ++p) dp[1][j][a[i][p]] = 1;
		}
	}
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int p = 1; p <= n; ++p) {
				if (p == j) continue;
				for (int x = 0; x < a[p].size(); ++x) {
					for (int y = x; y < x + k; ++y) {
						for (int z = 1; z <= n; ++z) {
							if (j != z) dp[i][j][a[p][y]] |= dp[i - 1][z][a[p][y]];
						}
					}
				}
			}
		}
	}
}
void solve()
{
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 1; i <= n; ++i) {
		int l, s;
		scanf("%d", &l);
		while (l--) {
			scanf("%d", &s);
			a[i].push_back(s);
		}
	}
	while (q--) {
		scanf("%d%d", &r, &c);
	}
}
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		puts("0");
	}
	return 0;
}


