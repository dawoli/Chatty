#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 1;
int G[N][N], d[N], n, c[15], a[15][N];
int mem[N][N], ans = 0x3f3f3f3f, m, k;
int cntt;
bool vis[N];
int prim(int s){
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i ++){
		d[i] = G[s][i]; //cout <<d[i] << ' ';
	} vis[s] = 1; //cout <<'\n';
	int ans = 0;
	for (int i = 1; i < n; i ++){
		int minn = 0x3f3f3f3f, minind = -1;
		for (int j = 1; j <= n; j ++){
			if (d[j] < minn && !vis[j]){
				minn = d[j], minind = j;
			}
		} //cout <<minn << ' ' << minind << '\n';
		if (minind == -1) return -1;
		vis[minind] = 1, d[minind] = 0, ans += minn;
		for (int j = 1; j <= n; j ++){
			d[j] = min(d[j], d[minind] + G[minind][j]);
		}
	}
	return ans;
}

void dfs(int cnt, int pos, int already){
	//cout <<"\t|";
	if (cnt > k || pos > n) return ;
	dfs(cnt, pos + 1, already);
	for (int i = 1; i <= n; i ++){
		mem[cntt][i] = G[pos][i];
		G[pos][i] = min(G[pos][i], a[cnt][i]);
		G[i][pos] = min(G[i][pos], a[cnt][i]);
	}
	already += c[cnt];
	int ret = already + prim(1);
	//cout << "(" << cnt << ' ' << pos <<' ' << already <<' ' << ret << ")\n";
	ans = min(ans, ret); ++ cntt;
	dfs(cnt + 1, pos + 1, already); -- cntt;
	for (int i = 1; i <= n; i ++){
		G[pos][i] = mem[cntt][i];
		G[i][pos] = mem[cntt][i];
	}
//	for (int i = 1; i <= n; i ++){
//		for (int j = 1; j <= n; j ++){
//			cout << (G[i][j] == 0x3f3f3f3f ? -1 : G[i][j]) << ' ';
//		}cout <<'\n';
//	}
}

int main(){
	freopen("road1.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	memset(G, 0x3f, sizeof(G));
	for (int i = 1; i <= n; i ++) G[i][i] = 0;
	for (int i = 1, u, v, w; i <= m; i ++){
		cin >> u >> v >> w;
		G[u][v] = min(G[u][v], w);
		G[v][u] = min(G[v][u], w);
	}
	for (int i = 0, x; i < k; i ++){
		cin >> c[i];
		for (int j = 1, w; j <= n; j ++){
			cin >> w; a[i][j] = w;
		}
	}
//	for (int i = 1; i <= n; i ++){
//		for (int j = 1; j <= n; j ++){
//			//cout << (G[i][j] == 0x3f3f3f3f ? -1 : G[i][j]) << ' ';
//		}//cout <<'\n';
//	}
	if (k == 0) cout << prim(1);
	else{
		ans = prim(1);
		dfs(0, 1, 0);
		cout << ans;
	}
	return 0;
}
