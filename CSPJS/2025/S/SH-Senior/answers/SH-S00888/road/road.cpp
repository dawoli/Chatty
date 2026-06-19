#include <bits/stdc++.h>
using namespace std;
int n, m, k, f[20010], cnt;
struct edge {
	int u, v, w;
} e[1100010];
int find(int x) {
	if(f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}
bool cmp(edge a, edge b) {
	return a.w < b.w;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		cin >> e[++cnt].u;
		cin >> e[cnt].v;
		cin >> e[cnt].w;
	}
	for(int i = 1; i <= k; i++) {
		int c; cin >> c;
		for(int j = 1; j <= n; j++) {
			cin >> e[++cnt].w;
			e[cnt].u = j; e[cnt].v = n + i; 
		}
	}
	//for(int i = 1; i <= cnt; i++)
	//	cout << e[i].u << " " << e[i].v << " " << e[i].w << "\n";
	//cout << "\n";
	sort(e + 1, e + cnt + 1, cmp);
	int sum = 0, ans = 0;
	for(int i = 1; i <= n + k; i++) f[i] = i;
	for(int i = 1; i <= cnt; i++) {
		int x = e[i].u, y = e[i].v, l = e[i].w;
		int a = find(x), b = find(y);
		//cout << x << " " << y << " " << l << "\n";
		//cout << find(x) << " " << find(y) << "\n";
		if(a == b) continue;
		sum++; ans += l;
		f[a] = b;
		if(sum >= n + k - 1) break;
		//cout << ans << "\n";
	}
	cout << ans << "\n";
	return 0;
}
