#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define REP(i, r, l) for (int i = (r); i >= (l); --i)
using namespace std;

int n, m, cnt;
string s;
int c[501];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s;
	rep (i, 1, n) {
		cin >> c[i];
		if (c[i] == 0) {
			++cnt;
		}
	}
	cout << cnt << '\n';
	return 0;
}
