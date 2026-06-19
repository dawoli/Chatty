#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 1-4
int f[10005];
int find(int x){
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int x, int y){
	int zx = find(x), zy = find(y);
	if (zx != zy){
		f[zx] = zy;
	}
}
struct edge{
	int a, b, w;
} e[1000005];
bool cmp(edge x, edge y){
	return x.w < y.w;
}

// special A
int v[10005][10005];
int kx[10005], dis[10005];
bool vis[10005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	if (k == 0){
		for (int i = 1; i <= n; i++)
			f[i] = i;
		for (int i = 1; i <= m; i++)
			cin >> e[i].a >> e[i].b >> e[i].w;
		sort(e+1, e+m+1, cmp);
		long long k = n-1, ans = 0;
		for (int i = 1; i <= m && k > 0; i++)
			if (find(e[i].a) != find(e[i].b)){
				k--;
				ans += e[i].w;
				merge(e[i].a, e[i].b);
			}
		cout << ans << '\n';
	} else {
		memset(v, 0x3f, sizeof(v));
		for (int i = 1; i <= m; i++){
			int a, b, w;
			cin >> a >> b >> w;
			v[a][b] = v[b][a] = min(v[a][b], w);
		}
		for (int i = 1; i <= k; i++){
			int c, tg;
			cin >> c;
			for (int j = 1; j <= n; j++){
				cin >> kx[j];
				if (kx[j] == 0) tg = j;
			} 
			for (int j = 1; j <= n; j++)
				v[tg][j] = v[j][tg] = min(v[tg][j], kx[j]);
		}
		memset(dis, 0x3f, sizeof(dis));
		long long ans = 0;
		dis[1] = 0;
		for (int i = 1; i <= n; i++){
			int x = 0;
			for (int j = 1; j <= n; j++)
				if (!vis[j] && dis[j] < dis[x]) x = j;
			vis[x] = true;
			ans += dis[x];
			for (int j = 1; j <= n; j++)
				dis[j] = min(dis[j], v[x][j]);
		}
		cout << ans << '\n';
	}
	return 0;
} 
