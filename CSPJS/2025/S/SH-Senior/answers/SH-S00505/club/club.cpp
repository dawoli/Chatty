#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> PII;
const int MAX_N = 1e5 + 10;

int n, a[MAX_N][3], b[MAX_N], c[MAX_N];

bool check() {
	for (int i = 1; i <= n; i++)
		if (a[i][2]) return false;
	return true;
}

void solve1() {
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += a[i][0], b[i] = a[i][1] - a[i][0];
	sort(b + 1, b + n + 1);
	for (int i = n; i > n / 2; i--)
		ans += b[i];
	printf("%d\n", ans);
}

void solve2() {
	priority_queue<PII, vector<PII>, greater<PII> > que12, que23;
	int sz1 = 0, sz2 = 0, sz3 = 0, ans = 0; a[n + 1][0] = a[n + 1][1] = a[n + 1][2] = 0;
	for (int i = 1; i <= n + 1; i++) {
		int ans1 = a[i][0], ans2 = a[i][1], ans3 = a[i][2];
		if (sz1 == n / 2) ans1 = 0;
		if (sz2 == n / 2) ans2 = 0;
		if (sz3 == n / 2) ans3 = 0;
		int ans4 = 0, ans5 = 0, ans6 = 0;
		if (sz1 == n / 2) ans4 = que12.top().fi + a[i][0];
		if (sz2 == n / 2) ans5 = que23.top().fi + a[i][1];
		int t = max(ans1, max(ans2, max(ans3, max(ans4, ans5)))); ans += t;
		if (t == ans1) sz1++, que12.push({a[i][1] - a[i][0], i});
		else if (t == ans4) {
			int t = que12.top().se; que12.pop();
			sz2++, que23.push({a[t][2] - a[t][1], t});
			que12.push({a[i][1] - a[i][0], i});
		}
		else if (t == ans2) sz2++, que23.push({a[i][2] - a[i][1], i});
		else if (t == ans5) que23.pop(), que23.push({a[i][2] - a[i][1], i}), sz3++;
		else sz3++;
	}
	printf("%d\n", ans);
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
	if (check()) solve1();
	else solve2();
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}
