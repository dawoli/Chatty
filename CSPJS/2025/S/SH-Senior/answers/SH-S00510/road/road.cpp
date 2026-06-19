#include <bits/stdc++.h>
using namespace std; 
int fa[20005], ans, c[15];
int n, m, k;
int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
struct road {
	int u, v, w;
}r[2000005];
bool cmp(road a, road b) {
	return a.w < b.w;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n+k; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) {
		cin >> r[i].u >> r[i].v >> r[i].w;
	}
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		for(int j = 1, x; j <= n; j++) {
			cin >> x;
			m++;
			r[m].u = n+i, r[m].v = j, r[m].w = x;
		}
	}
	sort(r+1, r+m+1, cmp);
	int cnt = n+k; 
	for(int i = 1; i <= m; i++) {
		int a = find(r[i].u);
		int b = find(r[i].v);
		if(a == b) continue;
		fa[b] = a;
		ans += r[i].w;
		cnt--;
		if(cnt <= 1) break;
	}
	cout << ans;
	return 0;
}
