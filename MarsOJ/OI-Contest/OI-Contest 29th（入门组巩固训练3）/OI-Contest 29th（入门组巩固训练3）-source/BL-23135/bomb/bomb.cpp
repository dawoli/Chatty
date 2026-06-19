#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char c[1005][1005];
int T, n, m, tot, id[1005][1005],
	dx[]={0, 0, -1, 1}, dy[]={1, -1, 0, 0};
struct edge {
	int v, w1, w2;
};
vector<edge> e[N];
struct node {
	pair<int, int> dis;
	int u;
	bool operator <(const node &a) const { return a.dis<dis; }
};
priority_queue<node> q;
pair<int, int> dis[N];
bool vis[N];
void dij () {
	for (int i=1; i<=tot; i=-~i)
		vis[i]=0,
		dis[i]={0x3f3f3f3f, 0x3f3f3f3f};
	dis[1]={0, 0};
	q.push({dis[1], 1});
	while (q.size()) {
		auto u=q.top().u;
		q.pop();
		if (vis[u])
			continue;
		vis[u]=1;
		for (auto &i:e[u]) {
			pair<int, int> tmp={dis[u].first+i.w1, dis[u].second+i.w2};
			if (dis[i.v]>tmp) {
				dis[i.v]=tmp;
				q.push({dis[i.v], i.v});
			}
		}
	}
}
int main () {
//	freopen("3.in", "r", stdin);
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		tot=0;
		for (int i=1; i<=n; i=-~i)
			for (int j=1; j<=m; j=-~j)
				cin >> c[i][j],
				id[i][j]=++tot;
		for (int i=1; i<=tot; i=-~i)
			e[i].erase(e[i].begin(), e[i].end());
		for (int i=1; i<=n; i=-~i) {
			for (int j=1; j<=m; j=-~j) {
				if (c[i][j]=='*')
					continue;
				for (int k=0; k<4; k=-~k) {
					int x=i+dx[k], y=j+dy[k];
					if (x>=1&&x<=n&&y>=1&&y<=m&&c[x][y]!='*')	
						e[id[i][j]].push_back({id[x][y], c[x][y]=='$', 1}),
						e[id[x][y]].push_back({id[i][j], c[i][j]=='$', 1});
				}
			}
		}
		dij();
		cout << dis[id[n][m]].first << ' ' << dis[id[n][m]].second << '\n';
	}
	return 0;
}
