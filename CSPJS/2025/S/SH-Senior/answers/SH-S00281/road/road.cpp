#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 10005;
int n, m, k, ans;
struct Edge{int a, b, c;} e[1000005];
int fa[N];

int find(int x) {
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

bool cmp(Edge x, Edge y) {
	return x.c < y.c;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		cin >> e[i].a >> e[i].b >> e[i].c;
	}
	if(k == 0) {
		sort(e + 1, e + n + 1, cmp);
		for(int i = 1; i <= n; i++) fa[i] = i;
		for(int i = 1; i <= m; i++) {
			int x = e[i].a, y = e[i].b;
			if(find(x) != find(y)) fa[fa[x]] = fa[y], ans += e[i].c;
		}
		cout << ans << endl;
	} else {
		for(int i = 1; i <= k; i++) {
			int c, a[N]; cin >> c;
			for(int j = 1; j <= n; j++) {
				cin >> a[i];
			}
			//problem
			/*for(int j = 1; j < n; j++) {
				for(int k = j + 1; k <= n; k++) {
					e[i].push_back(Edge{j, a[i]+c+a[j]});
					e[j].push_back(Edge{i, a[i]+c+a[j]});
				}
			}*/
		}
		cout << "0\n";
	}
	return 0;
} 
