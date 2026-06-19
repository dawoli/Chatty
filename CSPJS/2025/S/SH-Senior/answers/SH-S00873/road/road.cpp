#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int N1 = 15;
int n, m, k;
long long ans = 1e18 + 7;
int c[N1], a[N1][N], p[N], f[N], cnt = 0;

struct edge{
	int u;
	int v;
	int w;
	int t;
};

bool cmp(edge x, edge y){
	return x.w < y.w;
}

vector <edge> e;

int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

void MST(int cnt, int inii){
	long long ans0 = inii;
	for(int i = 1; i <= cnt; i ++) f[i] = i;
	for(int i = 0; i < m; i ++){
		int num = e[i].t;
		if(p[num] == 0) continue;
		int u = e[i].u; int fu = find(u);
		int v = e[i].v; int fv = find(v);
		if(fu == fv) continue;
		ans0 += e[i].w;
		f[fu] = fv;
	}
	ans = min(ans, ans0);
}

void dfs(int k){
	for(int i = 0; i <= (1 << k) - 1; i ++){
		int i1 = i;
		cnt = n;
		int i2 = 0;
		for(int j = 1; j <= k; j ++){
			if(i1 & 1) {
				p[j] = 1;
				i2 += c[j];
				cnt ++;
			}else {
				p[j] = 0;
			}
			i1 /= 2;
		}
		MST(cnt, i2);
	}
}


int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	p[0] = 1;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i ++){
		int u, v, w = 0;
		scanf("%d%d%d", &u, &v, &w);
		e.push_back({u, v, w, 0});
	} 
	for(int i = 1; i <= k; i ++){
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j ++){
			scanf("%d", &a[i][j]);
			e.push_back({n + i, j, a[i][j], i});
		}
	}
	m += k * n;
	sort(e.begin(), e.end(), cmp);
	//for(int i = 0; i < m; i ++) cout << e[i].u << " " << e[i].v << " " << e[i].w << " " << e[i].t << endl;
	dfs(k);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
