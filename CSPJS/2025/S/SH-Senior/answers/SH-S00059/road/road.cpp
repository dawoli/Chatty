#include<bits/stdc++.h>
using namespace std;
#define N 10020
#define NN 100010
#define M 1000010
int b[15][N], fa[N], cnt, c[15];
long long ans = 0;
int n, m, k, nn;
struct node{
	int x, y, w;
}a[M], ge[NN], gee[NN];
bool cmp(node x, node y) {
	return x.w < y.w;
}
int father(int x) {
	return fa[x] == x ? x : fa[x] = father(fa[x]);
}
void calc(long long tot) {
	for(int i = 1; i <= cnt; i++) {
		gee[i] = ge[i];
	}
	sort(gee + 1, gee + cnt + 1, cmp);
	for(int i = 1; i <= nn; i++) fa[i] = i;
	for(int i = 1; i <= cnt; i++) {
		int x = gee[i].x, y = gee[i].y, w = gee[i].w;
		if(father(x) == father(y)) continue;
		int fx = father(x), fy = father(y);
		fa[fx] = fy;
		tot += w;
	}
	ans = min(ans, tot);
}
void dfs(int dep, long long tot) {
	if(dep == k + 1) {
		calc(tot);
		return;
	}
	dfs(dep + 1, tot);
	nn++;
	for(int i = 1; i <= n; i++) {
		cnt++;
		ge[cnt].x = nn; ge[cnt].y = i; ge[cnt].w = b[dep][i];
	}
	dfs(dep + 1, tot + c[dep]);
	cnt -= n;
	nn--;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	nn = n;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].w);
	}
	sort(a + 1, a + m + 1, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) {
		int x = a[i].x, y = a[i].y, w = a[i].w;
		if(father(x) == father(y)) continue;
		int fx = father(x), fy = father(y);
		fa[fx] = fy;
		cnt++;
		ge[cnt] = a[i];
		ans += w;
	}
	for(int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j++) scanf("%d", &b[i][j]);
	}
	dfs(1, 0);
	printf("%lld", ans);
}
