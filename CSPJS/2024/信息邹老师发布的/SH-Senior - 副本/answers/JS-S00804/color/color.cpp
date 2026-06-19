# include <iostream>
# include <cstdio>
# include <algorithm>
# include <vector>
# include <cstring>

typedef long long LL;
const int NR = 2e5 + 10;
const int RG = 1e6 + 10;
int T, N, a[NR], next_same[NR];
LL ans;
std::vector <int> v[RG];
struct node {
	int x, y;
};
std::vector <node> pa;
int s[NR];
bool col[NR];

void reset() {
	pa.clear();
	memset(s, 0, sizeof s);
	memset(col, 0, sizeof col);
	memset(a, 0, sizeof a);
	memset(next_same, -1, sizeof next_same);
	N = 0; ans = 0;
	for (auto& _ : v) _.clear();
}

void solve(void) {
	for (int i = 1; i <= N; i++) {
		if (next_same[i] != -1) {
			pa.push_back((node){i, next_same[i]});
		}
	}
	int size = pa.size();
	int status = 1 << size;
	for (int i = 0; i < status; i++) {
		memset(col, 0, sizeof col);
		LL tmp = 0;
		for (int j = 0; j < size; j++) {
			if (i & (1 << j)) continue;
			col[pa[j].x] = col[pa[j].y] = true;
		}
		for (int j = 1; j <= N; j++) s[j] = s[j - 1] + (col[j] ? 1 : 0);
		for (int j = 1; j <= N; j++) {
			if (next_same[j] == -1) continue;
			if (col[j] == col[next_same[j]]) {
				if (col[j] && s[next_same[j] - 1] - s[j] == 0) tmp += a[j];
				if (col[j] == false && s[next_same[j]] - s[j] == next_same[j] - j - 1) tmp += a[j];
			}
		}
		ans = std::max(ans, tmp);
	}
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		reset();
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
		       	scanf("%d", a + i);
			v[a[i]].push_back(i);
		}
		for (int i = 1; i < RG; i++) {
			for (int j = 0; j + 1 < v[i].size(); j++) {
				next_same[v[i][j]] = v[i][j + 1];
			}
		}
		solve();
		printf("%lld\n", ans);
	}
	return 0;
}
