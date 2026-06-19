#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
long long n, m, k, tmp[15],c[15][10005], fa[1000025];
long long res = 0x3f3f3f3f3f3f3f3f;
struct E{
	int a, b, w;
}e[2200005], f[1000005];
bool cmp(E &a, E &b){
	return a.w<b.w;
}
int fd(int u){
	if(fa[u]!=u)fa[u] = fd(fa[u]);
	return fa[u];
}
void check(){
	int cnt = 0;
	long long rc = 0;
	memset(e, 0, sizeof e);
	for(int i = 1; i <= k; i++){
		if(tmp[i]==1){
			rc += c[i][0];
			for(int j = 1; j <= n;j++){
				e[++cnt].a = n+i;
				e[cnt].b = j;
				e[cnt].w = c[i][j];
			}
		}
	}
	for(int i = 1; i <= m; i++){
		e[++cnt] = f[i];
	}
	sort(e+1, e+cnt+1, cmp);
	for(int i = 1; i <= k+n; i++){
		fa[i] = i;
	}
	for(int i = 1; i <= cnt; i++){
		int u = e[i].a, v = e[i].b;
		u = fd(u);
		v = fd(v);
		if(u!=v){
			rc+=e[i].w;
			fa[u] = v;
		}
	}
	res = min(res, rc);
}
void find(int u){
	if(u>k){
		check();
		return;
	}
	tmp[u] = 1;
	find(u+1);
	tmp[u] = 0;
	find(u+1);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		scanf("%lld %lld %lld", &f[i].a, &f[i].b, &f[i].w);
	}
	bool flag = 1;
	for(int i = 1; i <= k; i++){
		for(int j = 0; j <= n; j++){
			cin >> c[i][j];
		}
		if(c[i][0]!=0)flag = 0;
	}
	if(flag){
		for(int i = 1; i <= k; i++)tmp[i] = 1;
		check();
	}
	else find(1);
	cout << res << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
