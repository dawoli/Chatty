#include<bits/stdc++.h>
//#include<vector>
using namespace std;
const int N = 1e4+20;
const int M = 1e7+10;
int dis[N], v[N], tot, edge[M], uu, vv, ww, s[M], ts, sed[M];
int n, m, k, al[N], a[N][N], tv, ef[M], es[M], q[N], e[30][N];
long long sum;
vector<pair<int, int> > g[N];
//
int dfs(int p, int ed, int fa){
	edge[++tot] = ed; es[tot] = p; ef[tot] = fa;
	ts++; s[ts] = p; sed[ts] = ed;
	if(v[p]) return dis[p];
	tv++; 
	v[p] = tv; dis[p] = tv;
	for(int i = 0; i < g[p].size(); i++){
		if(fa == g[p][i].first) continue;
		if(edge[dis[g[p][i].first]] == -1) continue;
		if(al[g[p][i].first] == dis[p]) continue;
		int x = dfs(g[p][i].first, g[p][i].second, p);
		if(x){
			int maxx = 0, xx;
			for(int i = x; i <= tot; i++){
				if(sed[i] >= maxx){
					xx = i;
					maxx = edge[i];
				}
			}
			tot--; ts--; s[ts+1] = 0; sed[ts+1] = 0;
			sum -= maxx; edge[xx] = -1; al[g[p][i].first] = x;
		}
	}
	s[ts] = 0; sed[ts] = 0; ts--;
	return 0;
}
//int n, m, k;

//struct qw{
//	int tiao, hao;
//}t[N];
//
//void ddd2(){
//	
//}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> uu >> vv >> ww;
		g[uu].push_back(make_pair(vv, ww));
		g[vv].push_back(make_pair(vv, ww));
		sum += ww;
//		a[uu][vv] = ww;
	}
	for(int i = 1; i <= k; i++){
		cin >> q[i];
		for(int j = 1; j <= n; j++){
			cin >> e[i][j];
		}
		for(int j = 1; j <= n; j++){
			for(int zaz = j+1; zaz <= n; zaz++){
				g[j].push_back(make_pair(zaz, q[i]+e[i][j]+e[i][zaz]));
				g[zaz].push_back(make_pair(j, q[i]+e[i][j]+e[i][zaz]));
			}
		}
	}
//	for(int i = 1; i <= n; i++){
//		t[i].tiao = g[i].size();
//		t[i].hao = i;
//	}
//	for(int i = 1; i <= n; i++){
//		
//	}
	int qwq = dfs(1, -1, 0);
	cout << sum;
	return 0;
}
