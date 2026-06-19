#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+5;
const int M = 2e6+5;

struct edge{
	int u, v, w;
	bool operator < (const edge & x) const {
		return w < x.w;
	}
} g[M];

int n, m, k, c[15], a[15][N];
int fa[N], cnt, ans, final_ans = 1e15;
bool opA = true;

int find(int x){
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

void merge(int i, int j){
	fa[find(i)] = find(j);
}

void kelusikaer(){
	for(int i=1; i<=m; i++){
		int u = g[i].u, v = g[i].v, w = g[i].w;
//		printf("%d %d %d\n", u, v, w);
		if(find(u) != find(v)){
			merge(u, v);
			cnt++, ans += w;
		}
	}
}

inline void input(int& t){
	t = 0;
	char c = ' ';
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9'){
		t = t * 10 + (c - '0');
		c = getchar();
	}
}

void dfs(int dep, int extra){
	if(dep > k){
		sort(g+1, g+m+1);
		for(int i=1; i<=n+k; i++) fa[i] = i;
		kelusikaer();
//		printf("%d %d %lld %lld\n",m, n, ans, extra);
		final_ans = min(final_ans, ans + extra);
		return;
	}
	dfs(dep+1, extra);
	
	for(int j=1; j<=n; j++){
		g[++m] = {n+dep, j, a[dep][j]};
	}
	dfs(dep+1, extra + c[dep]);
	
	m -= n;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	input(n); input(m); input(k);
	for(int i=1; i<=n+k; i++) fa[i] = i;
	for(int i=1; i<=m; i++){
		int u, v, w;
		input(u); input(v); input(w);
		g[i] = {u, v, w};
	}
	for(int i=1; i<=k; i++){
		input(c[i]);
		for(int j=1; j<=n; j++){
			input(a[i][j]);
		}
		if(c[i] != 0) opA = false;
	}
	
	if(k == 0){
		sort(g+1, g+m+1);
		kelusikaer();
		cout<<ans;
	} else if(opA == true){
		for(int i=1; i<=k; i++){
			for(int j=1; j<=n; j++){
				g[++m] = {n+i, j, a[i][j]};
			}
		}
		sort(g+1, g+m+1);
		kelusikaer();
		cout<<ans;
	} else {
		dfs(1, 0);
		cout<<final_ans;
	}
}

/*
6 8 0
1 2 2
1 3 3
2 3 1
2 4 4
3 5 5
4 5 8
4 6 9
5 6 7
*/

