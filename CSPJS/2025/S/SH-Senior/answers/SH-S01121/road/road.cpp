#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m, vis[N], k, c[N], a[15][N], build;
long long ans;
struct node {
	int v, w;
};
vector<node> mp[N];

int fr() {
	int x = 0, w = 1;char c = getchar();
	while(c < '0' || c > '9'){if(c == '-'){w = -1;} c = getchar();}
	while(c >= '0' && c <= '9'){x = x * 10 + c - '0'; c = getchar();}
	return x * w;
}

void prim() {
	priority_queue<pair<int, int> > q;
	int cnt = 0;
	q.push(make_pair(0, 1));
	int x, t;
	while(!q.empty()) {
		x = q.top().second;t = -q.top().first;
		q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		ans += t;
		for(node y : mp[x]) {
			q.push(make_pair(-y.w, y.v));
		}
	}
}

void prim2() {
	priority_queue<pair<int, int> > q;
	int cnt = 0;
	q.push(make_pair(0, 1));
	int x, t;
	while(!q.empty()) {
		x = q.top().second;t = -q.top().first;
		q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		ans += t;
		for(node y : mp[x]) {
			if(y.v <= n) q.push(make_pair(-y.w, y.v));
			else if(build & (1<<(y.v - n - 1))) {
				q.push(make_pair(-y.w,y.v));
//				cout << y.v << ' ';
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = fr(), m = fr(), k = fr();
	for(int i = 1, u, v, w;i <= m;i++) {
		cin >> u >> v >> w;
		mp[u].push_back((node){v, w});
		mp[v].push_back((node){u, w});
	}
	for(int j = 1;j <= k;j++) {
		c[j] = fr();
		for(int i = 1;i <= n;i++) {
			a[j][i] = fr();
			mp[i].push_back((node){j + n, a[j][i]});
			mp[j + n].push_back((node){i, a[j][i]});
		}
	}
	if(!c[1])prim();
	else {
		long long sum = 0;
		for(int i = 0;i < (1<<k);i++) {
			long long s = 0;
			for(int j = 0;j < k;j++) {
				if((1<<j) & i) s += c[j + 1];
			}
//			cout << i << ' ';
			ans = 0;
			memset(vis, 0, sizeof vis);
			build = i;
			prim2();
//			cout <<ans<<'\n';
			if(!sum) sum = ans + s;
			else sum = min(sum, ans + s);
		}
		ans = sum;
	}
	cout << ans;
	return 0;
} 
