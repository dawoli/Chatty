#include <bits/stdc++.h>
using namespace std;

int n, m, k, c[20], p[20][10010], f[10010], siz[10010], use[20], ans=2e9;
bool flaga = true;
struct node{
	int u, v, w;
} g[2000010];

bool cmp(node s, node t){
	return s.w < t.w;
}

int find(int x){
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}

void merge(int x, int y){
	int fx = find(x), fy = find(y);
	if (siz[fx] > siz[fy]) swap(fx, fy);
	f[fx] = fy;
	siz[fy] += siz[fx];
}

int kruskal(){
	for (int i = 1; i <= n; i++){
		f[i] = i;
		siz[i] = 1;
	}
	sort(g+1, g+m+1, cmp);
	int cnt = 0;
	long long ans = 0;
	for (int i = 1; i <= m; i++){
		if (find(g[i].u) != find(g[i].v)){
			merge(g[i].u, g[i].v);
			cnt++;
			ans += g[i].w;
		}
		if (cnt == n-1) break;
	}
	return ans;
}

void dfs(int step){
	if (step > n){
		int cnt = 0, tmp = 0;
		for (int i = 1; i <= k; i++){
			if (!use[i]) continue;
			tmp += c[i];
			for (int j = 1; j <= n; j++){
				if (i == j) continue;
				cnt++;
				g[m+cnt].u = i, g[m+cnt].v = j, g[m+cnt].w = p[i][j];
			}
		}
		m += cnt;
		ans = min(kruskal()+tmp, ans);
		m -= cnt;
		return;
	}
	use[step] = true;
	dfs(step+1);
	use[step] = false;
	dfs(step+1);
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> g[i].u >> g[i].v >> g[i].w;
	}
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		if (c[i]) flaga = false;
		bool f = false;
		for (int j = 1; j <= n; j++){
			cin >> p[i][j];
			if (p[i][j] == 0) f = true;
		}
		if (!f) flaga = false;
	}
	if (k == 0){
		kruskal();
	} else if (flaga){
		for (int i = 1; i <= k; i++){
			for (int j = 1; j <= n; j++){
				if (i == j) continue;
				g[++m].u = i, g[m].v = j, g[m].w = p[i][j];
			}
		}
		int ans1 = kruskal();
		cout << ans1 << endl;
	} else{
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
