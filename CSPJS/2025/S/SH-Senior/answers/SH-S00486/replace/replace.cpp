#include <bits/stdc++.h>
#define For(i, a, b) for (int i = (a); i <= (b); i ++)
#define foR(i, a, b) for (int i = (a); i >= (b); i --)
using namespace std;
int n, q;
unsigned long long hsh[400005][2], ha[400005][2];
unsigned long long p[400005];
int st[400005], ed[400005], ans[400005];
char s1[5000005], s2[5000005];
struct node {int cx, lll, rrr;}a[400005];
struct Query {int cx, lll, rrr, id;}u[400005];
unsigned long long getha0 (int x, int y) {return ha[y][0] - ha[x - 1][0] * p[y - x + 1];}
unsigned long long getha1 (int x, int y) {return ha[y][1] - ha[x - 1][1] * p[y - x + 1];}
bool cmp (node n1, node n2) {return n1.cx < n2.cx || (n1.cx == n2.cx && n1.lll < n2.lll);}
bool cmp_ (Query q1, Query q2) {return q1.cx < q2.cx || (q1.cx == q2.cx && q1.lll < q2.lll);}
int c[10000050];
vector <int> cl;
void add (int x) {
	x += 5000001;
	for (; x <= 10000005; x += x & -x) {
		c[x] ++;
		cl.push_back (x);
	}
}
int query (int x) {
	x += 5000001;
	int res = 0;
	for (; x; x -= x & -x) res += c[x];
	return res;
}
signed main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	p[0] = 1;
	For (i, 1, 200000) p[i] = p[i - 1] * 13331;
	scanf ("%d%d", &n, &q);
	For (i, 1, n) {
		scanf ("%s%s", s1 + 1, s2 + 1);
		int len = strlen (s1 + 1);
		int l = 1, r = len;
		while (l <= len && s1[l] == s2[l]) ++ l;
		while (r >= 1 && s1[r] == s2[r]) -- r;
		a[i] = {-100000000, 1, 1};
		if (l > r) continue;
		st[i] = l - 1;
		ed[i] = len - r;
		unsigned long long ha = 0;
		For (i, 1, len) ha = ha * 13331 + s1[i];
		hsh[i][0] = ha;
		ha = 0;
		For (i, 1, len) ha = ha * 13331 + s2[i];
		hsh[i][1] = ha;
		For (j, 1, len) if (s1[j] == 'b') {
			a[i].cx = j;
			a[i].lll = j - 1;
			a[i].rrr = len - j;
		}
		For (j, 1, len) if (s2[j] == 'b') a[i].cx -= j;
	}
	sort (a + 1, a + n + 1, cmp);
	if (n * q <= 100000000) {
		while (q --) {
			scanf ("%s%s", s1 + 1, s2 + 1);
			int len = strlen (s1 + 1);
			int l = 1, r = len;
			while (l <= len && s1[l] == s2[l]) ++ l;
			while (r >= 1 && s1[r] == s2[r]) -- r;
			For (i, 1, len) ha[i][0] = ha[i - 1][0] * 13331 + s1[i];
			For (i, 1, len) ha[i][1] = ha[i - 1][1] * 13331 + s2[i];
			int res = 0;
			For (i, 1, n) {
				int ll = l - st[i], rr = r + ed[i];
				if (ll < 1 || rr > len) continue;
				if (getha0 (ll, rr) == hsh[i][0] && getha1 (ll, rr) == hsh[i][1]) ++ res;
			}
			printf ("%d\n", res);
		}
	} else {
		int cnt = 0;
		while (q --) {
			scanf ("%s%s", s1 + 1, s2 + 1);
			int len = strlen (s1 + 1);
			For (i, 1, len) {
				if (s1[i] == 'b') u[++ cnt] = {i, i - 1, len - i, cnt};
				if (s2[i] == 'b') u[cnt].cx -= i;
			}
		}
		sort (u + 1, u + cnt + 1, cmp_);
		int l = 1;
		For (i, 1, cnt) {
			while (l <= n && a[l].cx < u[i].cx) ++ l;
			if (l > n) break;
			if (a[l].cx > u[i].cx) continue;
			for (int i : cl) c[i] = 0;
			cl.clear ();
			int j = i;
			while (j <= n) {
				while (a[l].cx == u[j].cx && a[l].lll <= u[j].lll) {
					add (a[l].rrr);
					++ l;
				}
				ans[u[j].id] = query (u[j].rrr);
				if (j <= n && u[j + 1].cx == u[j].cx) ++ j;
				else break;
			}
			i = j;
		}
		For (i, 1, cnt) cout << ans[i] << '\n';
	}
	return 0;
}
/*
两种做法：
1. n 个字符串一个个试，O (n + L)
2. 若 L 较短，则枚举其所有子串，再用桶查询
shijianfuzadu O (L/b * n) + O (l / b * n) + O (b^2 * n)
4 2
abaa aaba
baa aba
aaab aaba
baaa abaa
aabaa aaaba
aabaa aaaba
*/
