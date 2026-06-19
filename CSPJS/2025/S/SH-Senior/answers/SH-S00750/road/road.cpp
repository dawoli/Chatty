#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans;
vector<int> to[10105];
int c[15],vis[10105];
map<pair<int,int>,int> d;

void prim() {
	queue<int> q;
	q.push(1);
	int cnt = 0;
	while(!q.empty()) {
		int u = q.front();
		vis[u] = 1;
		//cout << u <<' ';
		cnt++;
		if(cnt == n) break;
		q.pop();
		int minn = 1e9,loc;
		for(int i = 0; i < to[u].size(); i++) {
			int nw = to[u][i];
			if(!vis[nw]) {
				if(d[{u,nw}] < minn) {
					minn = d[{u,nw}];
					loc = nw;
				} 
			}
		}
		ans += minn;
		q.push(loc);
	}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		to[u].push_back(v);
		to[v].push_back(u);
		d[{u,v}] = w;
		d[{v,w}] = w;
	}
	if(k == 0) {
		//cout << d[{1,2}] << endl;
		prim();
		cout << ans;
		return 0;
	}
//	for(int i = 1; i <= k; i++) {
//		cin >> c[i];
//		for(int j = 1; i <= n; i++) {
//			int u = n+i,v = j;
//			int w;
//			cin >> w;
//			to[u].push_back(v);
//			to[v].push_back(u);
//			d[{u,v}] = w;
//			d[{v,w}] = w;
//		}
//	}
	
}

/*
5 6 0
1 2 4
1 3 3
1 5 1
2 3 6
3 5 8
1 6 7
*/
