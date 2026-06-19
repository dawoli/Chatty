#include<bits/stdc++.h>
typedef long long ll;
const int N = 1e4 + 5,M = 1e6 + 5;
int fa[N]; 
struct EDGE{int v,w;};
std::vector<EDGE> g[N];
int a[15][N]; 
struct side{
	int u,v,w;
	bool operator<(side x){return w < x.w;}
}s[M + N];
int getroot(int x){return fa[x] == x ? x : fa[x] = getroot(fa[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(0);
	int n,m,k;std::cin >> n >> m >> k;
	for (int i = 1;i <= m;i++){
		std::cin >> s[i].u >> s[i].v >> s[i].w;
		g[s[i].u].push_back({s[i].v,s[i].w});
		g[s[i].v].push_back({s[i].u,s[i].w});
	}
	for (int i = 1;i <= k;i++){
		std::cin >> a[i][0];
		for (int j = 1;j <= n;j++) std::cin >> a[i][j];
	}
	if (k == 0){
		std::sort(s + 1,s + 1 + m);
		for (int i = 1;i <= n;i++) fa[i] = i;
		ll ans = 0;
		for (int i = 1;i <= m;i++)
			if (getroot(s[i].u) != getroot(s[i].v)){
				ans += s[i].w;
				fa[getroot(s[i].u)] = getroot(s[i].v);
			}
		std::cout << ans << '\n';
		return 0;
	}
	int cnt = m;
	for (int i = 1;i <= k;i++){
		for (int j = 1;j <= n;j++)
			if (a[i][j] == 0){
				for (int t = 1;t <= n;t++)
					if (t != j){
						s[++cnt].u = t;
						s[cnt].v = j;
						s[cnt].w = a[i][t];
					}
				break;
			}
	}
	std::sort(s + 1,s + 1 + cnt);
	for (int i = 1;i <= n;i++) fa[i] = i;
	ll ans = 0;
	for (int i = 1;i <= cnt;i++)
		if (getroot(s[i].u) != getroot(s[i].v)){
			ans += s[i].w;
			fa[getroot(s[i].u)] = getroot(s[i].v);
		}
	std::cout << ans << '\n';
	return 0;
}
