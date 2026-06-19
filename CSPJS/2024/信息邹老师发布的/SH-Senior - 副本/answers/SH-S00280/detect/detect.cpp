#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 100005
int T, n, m, L, V, d[N], v[N], a[N], p[M], nS;
struct Seg {int l, r;} s[N];
bool cmp(Seg a, Seg b) {
	return a.r != b.r ? a.r < b.r : a.l < b.l;
}
void solve() {
	int nS = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] > p[m]) continue;
		if (!a[i] && v[i] > V)
			s[++nS].l = lower_bound(p + 1, p + m + 1, d[i]) - p,
			s[nS].r = m;
		if (a[i] < 0 && v[i] > V) {
			int pos = (V * V - v[i] * v[i] + 1) / (2 * a[i]) + d[i];
			int l = lower_bound(p + 1, p + m + 1, d[i]) - p;
			if (p[l] > pos) continue;
			s[++nS].l = l;
			s[nS].r = upper_bound(p + 1, p + m + 1, pos) - p - 1;
		}
		if (a[i] > 0) {
			int pos = (V * V - v[i] * v[i]) / (2 * a[i]) + d[i] + 1;
			if (pos > p[m]) continue;
			s[++nS].l = lower_bound(p + 1, p + m + 1, pos) - p;
			s[nS].r = m;
		}
	}
	sort(s + 1, s + nS + 1, cmp);
	int maxr = 0, ans = 0;
	for (int i = 1; i <= nS; i++)
		if (maxr < s[i].l)
			ans++, maxr = s[i].r;
	printf("%d %d\n", nS, m - ans);
}
void solveBF() {solve();}
void solveA() {
	int l = p[m], ans = 0;
	for (int i = 1; i <= n; i++)
		if (v[i] > V && d[i] <= l) ans++;
	if (ans) printf("%d %d\n", ans, m - 1);
	else printf("0 %d\n", m);
}
void solveB() {
	int l = p[m], ans = 0;
	for (int i = 1; i <= n; i++)
		if (d[i] <= l && v[i] * v[i] + 2 * 
			a[i] * (l - d[i]) > V * V) ans++;
	if (ans) printf("%d %d\n", ans, m - 1);
	else printf("0 %d\n", m);
}
void solveC() {solve();}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &n, &m, &L, &V);
		bool isa0 = 1, isag = 1, isal = 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", d + i, v + i, a + i);
			if (a[i] != 0) isa0 = 0;
			if (a[i] <= 0) isag = 0;
			if (a[i] >= 0) isal = 0;
		}
		for (int i = 1; i <= m; i++)
			scanf("%d", p + i);
		sort(p + 1, p + m + 1);
		if (n <= 10 && m <= 10) solveBF();
		else if (isa0) solveA();
		else if (isag) solveB();
		else if (isal) solveC(); 
		else solve();
	}
	return 0;
}
