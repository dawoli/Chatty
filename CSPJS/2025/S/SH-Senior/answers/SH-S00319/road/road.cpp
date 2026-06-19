#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e4 + 5, MAXM = 1e6 + 5, MAXK = 12;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct edge{
	int u, v;
	long long val;
	bool operator <(edge other){
		return val < other.val;
	}
};
int n, m, k;
int fa[MAXN];
int cntedge, cnttree;
edge e[MAXM], et[MAXN], eq[MAXM + MAXK * MAXN];
int status;
long long c[MAXK], a[MAXK][MAXN];
long long ans = INF;
template<typename T> inline void readint(T &x){
	char ctmp = getchar();
	bool neg = 0;
	while(ctmp < '0' || ctmp > '9'){
		if(ctmp == '-')neg = 1;
		ctmp = getchar();
	}
	x = 0;
	while(ctmp >= '0' && ctmp <= '9'){
		x = x * 10 + ctmp - 48;
		ctmp = getchar();
	}
	if(neg)x = -x;
}
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
inline void init(){
	for(int i = 1;i <= n;i++)fa[i] = i;
	cntedge = 0;
	for(int i = 1;i <= n - 1;i++){
		eq[++cntedge] = et[i];
	}
	for(int i = 1;i <= k;i++){
		if(status & (1 << i))fa[n + i] = n + i;
	}
}
long long kruskal_init(){
	long long res = 0;
	sort(e + 1, e + m + 1);
	for(int i = 1;i <= m;i++){
		if(find(e[i].u) == find(e[i].v))continue;
		fa[find(e[i].u)] = find(e[i].v);
		et[++cnttree] = e[i];
		res += e[i].val;
	}
	return res;
}
long long kruskal(){
	long long res = 0;
	int cntedge = n - 1;
	for(int i = 1;i <= k;i++){
		if(status & (1 << i)){
			res += c[i];
			for(int j = 1;j <= n;j++){
				eq[++cntedge].u = n + i;
				eq[cntedge].v = j;
				eq[cntedge].val = a[i][j];
			}
		}
	}
	sort(eq + 1, eq + cntedge + 1);
	for(int i = 1;i <= cntedge;i++){
		if(find(eq[i].u) == find(eq[i].v))continue;
		fa[find(eq[i].u)] = find(eq[i].v);
		res += eq[i].val;
	}
	return res;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	readint(n);
	readint(m);
	readint(k);
	for(int i = 1;i <= m;i++){
		readint(e[i].u);
		readint(e[i].v);
		readint(e[i].val);
	}
	for(int i = 1;i <= n;i++)fa[i] = i;
	ans = kruskal_init();
	for(int i = 1;i <= k;i++){
		readint(c[i]);
		for(int j = 1;j <= n;j++){
			readint(a[i][j]);
		}
	}
	for(status = 2;status < (1 << (k + 1));status += 2){
		init();
		ans = min(ans, kruskal());
	}
	printf("%lld", ans);
	return 0;
}
