#include <bits/stdc++.h>
using namespace std;

int n, m, k, t, XX0, YY0, d, ans = 1;
char s[1011][1011];
bool b[1011][1011];

inline void solve() {
	ans = 1; 
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d%d", &XX0, &YY0, &d);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	memset(b, false, sizeof(b));
	b[XX0][YY0] = true;
	for (int i = 1; i <= k; i++) {
		bool bb = false;
		if (!d) {
			if (YY0 + 1 <= m)
				if (s[XX0][YY0 + 1] == '.') {
					if (b[XX0][YY0 + 1] == false)
						++ans, b[XX0][YY0 + 1] = true;
					++YY0, bb = true;
				}
		} else if (d == 1) {
			if (XX0 + 1 <= n)
				if (s[XX0 + 1][YY0] == '.') {
					if (!b[XX0 + 1][YY0])
						++ans, b[XX0 + 1][YY0] = true;
					++XX0, bb = true;
				}
		} else if (d == 2) {
			if (YY0 - 1 >= 1)
				if (s[XX0][YY0 - 1] == '.') {
					if (!b[XX0][YY0 - 1])
						++ans, b[XX0][YY0 - 1] = true;
					--YY0, bb = true;
				}
		} else {
			if (XX0 - 1 >= 1)
				if (s[XX0 - 1][YY0] == '.') {
					if (!b[XX0 - 1][YY0])
						++ans, b[XX0 - 1][YY0] = true;
					--XX0, bb = true;
				}
		}
		if (!bb)
			d = (d + 1) % 4;
	}
	printf("%d\n", ans);
}

int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	scanf("%d", &t);
	for ( ; t--; ) {
		solve();
	}
	return 0;
}
