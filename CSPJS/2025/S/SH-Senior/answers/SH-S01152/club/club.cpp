#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pii pair<int, int>
#define mp make_pair
using namespace std;
int rd() {
	int res = 0, c = getchar();
	while (c < 48 || c > 57) c = getchar();
	while (48 <= c && c <= 57) res = (res << 3) + (res << 1) + (c ^ 48), c = getchar();
	return res;
}
void wr(int x) {
	if (x > 9) wr(x / 10);
	putchar(x % 10 + 48);
}
const int maxn = 1e5 + 5;
int n, id, ans;
int a[maxn][4];
int l[maxn];
int d[maxn];
int c[4];
vector<int> q;
void MAIN() {
	id = -1, ans = 0;
	for (int i = 0; i < 3; i ++) c[i] = 0;
	q.clear();
	n = rd();
	for (int i = 1; i <= n; i ++) {
		a[i][0] = rd(), a[i][1] = rd(), a[i][2] = rd();
		pii b[4] = {mp(a[i][0], 0), mp(a[i][1], 1), mp(a[i][2], 2)};
		sort(b, b + 3);
		l[i] = b[2].y;
		c[b[2].y] ++;
		d[i] = b[2].x - b[1].x;
		ans += b[2].x;
	}
	for (int i = 0; i < 3; i ++) if (c[i] > n / 2) id = i;
	if (~id) {
		for (int i = 1; i <= n; i ++) if (l[i] == id) q.push_back(d[i]);
		sort(q.begin(), q.end());
		for (int i = 0; i < c[id] - n / 2; i ++) ans -= q[i];
	}
	wr(ans), putchar('\n');
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = rd();
	while (T --) MAIN();
}
