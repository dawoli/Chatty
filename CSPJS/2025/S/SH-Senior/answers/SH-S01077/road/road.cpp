#include<iostream>
#include<fstream>
#include<algorithm>
std::ifstream fin("road.in");
std::ofstream fout("road.out");

struct node{
	int u, v; long long w;
	bool operator < (const node&aa) {
		return w < aa.w;
	}
}e[2000005], ee[11005][1105], wait[20005][25];
long long plus[25];

int fa[20005]; int a[20005]; int sz[20005];
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

int main(){
	int n, m, k; fin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		fin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
	std::sort(e+1, e+m+1); long long ans = 0; int top = 1;
	for (int i = 1; i <= m; ++i) {
		int f1 = find(e[i].u), f2 = find(e[i].v); 
		if (f1 != f2) {
			ans += e[i].w; ee[top++][0] = e[i];
			if (sz[f1] < sz[f2]) fa[f1] = f2, sz[f2] += sz[f1];
			else fa[f2] = f1, sz[f1] += sz[f2];
		}
	}
	for (int i = 1; i <= k; ++i) {
		long long c;
		fin >> c; int mini = 1e9+1; int wh = 0;
		for (int j = 1; j <= n; ++j) {
			fin >> a[j]; if (a[j] < mini) mini = a[j], wh = j;
		}
		int tempo = 1; plus[i] = c + mini;
		for (int j = 1; j <= n; ++j) {
			if (j != wh) {
				wait[tempo++][i] = {wh, j, a[j]};
			}
		}
	}
	for (int i = 1; i < (1LL<<k); ++i) {
		for (int j = 1; j <= n; ++j) fa[j] = j, sz[j] = 1;
		int copy = i, now = 1; int pl = 0; long long temans = 0;
		while (copy > 0) {
			if (copy % 2 == 1) {
				temans += plus[now];
				pl = now;
			}
			now++; copy /= 2;
		}
		for (int j = 1; j < n; ++j) {
			e[j] = wait[j][pl];
		}
		copy = i - (1LL<<(pl-1));
		for (int j = 1; j < n; ++j) {
			e[n+j-1] = ee[j][copy];
		}
		std::sort(e+1, e+2*n-1);
		top = 1;
		for (int j = 1; j < 2*n-1; ++j) {
			int f1 = find(e[j].u), f2 = find(e[j].v);
			if (f1 != f2) {
				temans += e[j].w; ee[top++][i] = e[j];
				if (sz[f1] < sz[f2]) fa[f1] = f2, sz[f2] += sz[f1];
				else fa[f2] = f1, sz[f1] += sz[f2];
			}
		}
		ans = std::min(ans, temans);
	}
	fout << ans;
}
