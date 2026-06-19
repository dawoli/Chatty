#include <bits/stdc++.h>
#define For(i, a, b) for (int i = (a); i <= (b); i ++)
#define foR(i, a, b) for (int i = (a); i >= (b); i --)
#define int long long
using namespace std;
int T, cnt;
int n, m, L, V;
int l[100005], r[100005], p[100005];
int lg[100005], pre[18], st[100005][17];
int s[100005], dp[100005];
struct Node {int x, y;}a[100005];
bool cmp (Node n1, Node n2) {return n1.y < n2.y;}
void init () {
	For (i, 0, 16) pre[i] = 1LL << i;
	lg[1] = 0;
	For (i, 2, 100000) lg[i] = lg[i / 2] + 1;
}
int query (int x, int y) {
	int l = lg[y - x + 1];
	return min (st[y][l], st[x + pre[l] - 1][l]);
}
signed main () {
	freopen ("detect.in", "r", stdin);
	freopen ("detect.out", "w", stdout);
	init ();
	scanf ("%lld", &T);
	while (T --) {
		cnt = 0;
		For (i, 1, 100000) {
			dp[i] = 100000;
			l[i] = r[i] = 11451419;
		}
		For (i, 1, 100000) For (j, 0, 16) st[i][j] = 100000;
		scanf ("%lld%lld%lld%lld", &n, &m, &L, &V);
		For (i, 1, n) {
			int d, v, a;
			scanf ("%lld%lld%lld", &d, &v, &a);
			if (v < V) {
				if (a > 0) {
					double t = (V - v) * 1.0 / a + 0.00000001;//这个时刻正好不超速，这个时刻加 eps 超速
					//此时走了 v0t + 1/2 a * t ^ 2
					int xx = ceil (v * t + a * t * t / 2) + d;//从这个位置开始超速
					l[i] = xx;
					r[i] = L;
				}
			} else {
				if (a < 0) {//a > 0 任何时刻都超速，直接记录答案
					double t = (V - v) * 1.0 / a - 0.00000001;//这个时刻正好不超速，这个时刻减 eps 超速
					//此时走了 v0t + 1/2 a * t ^ 2
					int xx = floor (v * t + a * t * t / 2) + d;//这个时刻及之前全部超速
					xx = min (xx, L);
					l[i] = d;
					r[i] = xx;
				} else if (v == V) {//开始的那一瞬间不超速
					if (a > 0) {
						l[i] = d + 1;
						r[i] = L;
					}
				} else {
					l[i] = d;
					r[i] = L;
				}
			}
		}
		For (i, 0, L) s[i] = 0;
		For (i, 1, m) {
			scanf ("%lld", &p[i]);
			s[p[i] ] ++;
		}
		For (i, 1, L) s[i] += s[i - 1];
		int ans1 = 0;
		For (i, 1, n) {
			if (r[i] == 11451419) continue;
			if (s[r[i] ] - (l[i] == 0 ? 0 : s[l[i] - 1]) ) {
				++ ans1;
				a[++ cnt] = {l[i], r[i]};
			}
		}
		printf ("%lld ", ans1);
		sort (a + 1, a + cnt + 1, cmp);
		int l = 0, tail = 0;//存储当前检测不到的东西中最大左端点最小右端点
		int lp = 0;
		For (i, 1, m) {
			while (tail != cnt && a[tail + 1].y < p[i]) {
				++ tail;
				l = max (l, a[tail].x);
			}
			if (tail == 0) dp[i] = 1;
			else {
				while (p[lp] < l) ++ lp;
				dp[i] = query (lp, i - 1) + 1;
			}//7 的方案：7 4 1 
			st[i][0] = dp[i];
			For (j, 1, 16) if (i > pre[j - 1]) st[i][j] = min (st[i][j - 1], st[i - pre[j - 1] ][j - 1]);
		}
		int ans = 100000, maxl = 0;
		For (i, 1, cnt) maxl = max (maxl, a[i].x);
		foR (i, m, 1) {
			if (p[i] < maxl) break;
			ans = min (ans, dp[i]);
		}
		printf ("%lld\n", m - ans);
	}
	return 0;
}
/*
求出如果在 i 放测速器，那么至少要在位置多少放一个。
tip：先求出位置 i 检测不到的东西中，右端点最靠后的那一个 r
，在求出位置 i 检测不到的东西中，左端点最靠后的那一个 l

r < i 的检测器中

则 f[i] 可以从 l 到 r 之间转移 

必须 n log m 否则过不掉

容易发现能取的 l 和 r 是逐渐递增的
*/
