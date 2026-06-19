#include <bits/stdc++.h>

const int N = 1e5 + 2;

int n, m, aa[N], a[N], K;
struct query {
	int c, i;
} c[N];
long long ans[N];
bool match[21][N];
long long f[21][N], g[21][N];
int ll[21], rr[21];

void solve() {
	memset(g, 0x00, sizeof g);
	for (int i = 1; i <= m; i++) {
		ans[i] = 0;
	}
	for (int i = 1; i <= (1 << K); i++) {
		f[0][i] = i;
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= (1 << (K - i)); j++) {
			f[i][j] = f[i - 1][j * 2] + f[i - 1][j * 2 - 1];
		}
	}
	
	
	// 1 left ;; 2 right
	for (int i = 1, p = 1, k = 0; i <= n; i++) {
		g[0][i] = i;
		if (i > (1 << k)) {
			k++;
		}
		int now = i;
		for (int j = 1; j <= k; j++) {
			now = (now + 1) / 2;
			if (match[j][now]) { // right
				if (g[j - 1][now * 2] == 0) {
					g[j][now] = 0;
					f[j][now] = f[j - 1][now * 2 - 1] + f[j - 1][now * 2];
				} else {
					if (a[g[j - 1][now * 2]] >= j) {
						g[j][now] = g[j - 1][now * 2];
						f[j][now] = f[j - 1][now * 2];
					} else {
						g[j][now] = g[j - 1][now * 2 - 1];
						f[j][now] = f[j - 1][now * 2 - 1];
					}
				}
			} else { // left
				if (g[j - 1][now * 2 - 1] == 0) {
					g[j][now] = 0;
					f[j][now] = f[j - 1][now * 2 - 1] + f[j - 1][now * 2];
				} else {
					if (a[g[j - 1][now * 2 - 1]] >= j) {
						g[j][now] = g[j - 1][now * 2 - 1];
						f[j][now] = f[j - 1][now * 2 - 1];
					} else {
						g[j][now] = g[j - 1][now * 2];
						f[j][now] = f[j - 1][now * 2];
					}
				}
			}
		}
		while (p <= m && c[p].c == i) {
			ans[c[p].i] = f[k][1];
			p++;
		}
	}
	long long tans = 0;
	for (int i = 1; i <= m; i++) {
		tans ^= 1ll * ans[i] * i;
		//std::cout << ans[i] << ' ';
	}//std::cout << '\n';
	std::cout << tans << '\n';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
//	freopen("arena3.in", "r", stdin);
//	freopen("ans.txt", "w", stdout);
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> aa[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> c[i].c;
		c[i].i = i;
	}
	std::sort(c + 1, c + 1 + m, [](const query ox, const query oy) {
		return ox.c < oy.c;
	});
	for (int i = 1; i <= 20; i++) {
		if ((1 << i) >= n) {
			K = i;
			break;
		}
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= (1 << (K - i)); j++) {
			char o;
			std::cin >> o;
			if (o == '0') {
				match[i][j] = 0;
			} else {
				match[i][j] = 1;
			}
		}
	}
	int TT;
	std::cin >> TT;
	while (TT--) {
		int T[4];
		for (int i = 0; i < 4; i++) {
			std::cin >> T[i];
		}
		for (int i = 1; i <= n; i++) {
			a[i] =  aa[i] ^ T[i % 4];
		}
		solve();
	}
}
