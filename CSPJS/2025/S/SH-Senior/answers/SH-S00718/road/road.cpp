#include<bits/stdc++.h>
#define LL long long
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define F(a, i, j, k) for(LL a = (LL)(i); a <= (LL)(j); a += (LL)(k))
#define R(a, i, j, k) for(LL a = (LL)(i); a >= (LL)(j); a -= (LL)(k))
using namespace std;

const LL M = 1e7 + 10;
const LL N = 1e4 + 10;

LL n, m, kk;
LL c[N], a[N][N];
struct Edge{
	LL u, v, w;
};
Edge dis[M];
LL zzd[M];
LL Mp[N][N];
bool vis[N];

LL fa[N], ans = 0ll, cnt;

inline void Init(){
	F(i, 1, n, 1)
		fa[i] = i;
} 

LL Find(LL x){
	if(fa[x] == x)
		return fa[x];
	return (fa[x] = Find(fa[x]));
}

bool cmp(Edge A, Edge B){
	return A.w < B.w;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m >> kk;
	F(i, 1, n, 1){
		F(j, 1, n, 1){
			Mp[i][j] = -1;
			Mp[j][i] = -1;
		}
	}
	F(i, 1, m, 1){
		LL u, v, w;
		cin >> u >> v >> w;
		dis[i].u = min(u, v), dis[i].v = max(u, v), dis[i].w = w;
		zzd[i] = -1;
		Mp[u][v] = i;
		Mp[v][u] = i;
	}
	cnt = m;
	F(i, 1, kk, 1){
		cin >> c[i];
		F(j, 1, n, 1)
			cin >> a[i][j];
	}
	Init();
	F(i, 1, n, 1){
		F(j, 1, kk, 1){
			F(k, 1, n, 1){
				if(i == k)
					continue;
				if(Mp[i][k] != -1){
					if(a[j][i] + c[j] + a[j][k] < dis[Mp[i][k]].w){
						dis[Mp[i][k]].w = a[j][i] + c[j] + a[j][k];
						zzd[cnt] = j;
					}
				}
				else{
					cnt++;
					dis[cnt].u = min(i, k), dis[cnt].v = max(i, k);
					Mp[i][k] = cnt;
					Mp[k][i] = cnt;
					dis[cnt].w = a[j][i] + c[j] + a[j][k];
					zzd[cnt] = j;
				}
			}
		}
	}
	sort(dis + 1, dis + cnt + 1, cmp);
	memset(vis, false, sizeof vis);
	F(i, 1, cnt, 1){
		LL fx = Find(dis[i].u);
		LL fy = Find(dis[i].v);
		if(fx == fy)
			continue;
		if(zzd[i] != -1){
			if(!vis[zzd[i]])
				vis[zzd[i]] = true;
			else
				ans -= c[zzd[i]];
		}
		fa[fx] = fy;
		ans += dis[i].w;
	}
//	cout << 1 << '\n'; 
	cout << ans << '\n';
	return 0;
}
