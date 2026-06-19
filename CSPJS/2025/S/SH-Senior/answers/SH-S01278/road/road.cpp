#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, u, v, c, cnt, ans, fa[1919810];
struct edge{
	int u, v, c;
} e[1919810];
bool cmp(edge a, edge b){
	return a.c < b.c;
}
int find(int x){
	if(fa[x] == x){
		return x;
	}
	return fa[x] = find(fa[x]);
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	for(int i = 1; i <= m; i++){
		scanf("%lld %lld %lld", &e[i].u, &e[i].v, &e[i].c);
	}
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= m; i++){
		if(find(e[i].u) != find(e[i].v)){
			ans += e[i].c;
			fa[find(e[i].u)] = find(e[i].v);
		}
	}
	printf("%lld", ans);
	return 0;
}
