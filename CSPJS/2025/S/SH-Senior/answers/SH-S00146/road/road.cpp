#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
ll ans = 114514191;

struct Edge {
	int to, w, next;
} edge[3000000];
struct Task {
	int c, to;
	bool operator< (Task o) const {
		return c > o.c;
	}
};
int head[114514], cnt=0;
void ade(int u, int v, int w){
	edge[++cnt] = (Edge){v, w, head[u]};
	head[u] = cnt;
}
bool vis[114514], de[114];
int ext_cst[114];

int bfs(){
	int ans=0, m_cnt=0;
	Edge e;
	Task t;
	priority_queue<Task> q;
	q.push({0, 1});
	while (!q.empty()){
		t = q.top();
		q.pop();
		if (vis[t.to]) continue;
		vis[t.to] = true;
		ans += t.c;
		if (t.to > n) {
			if (de[t.to-n-100]){
				ans -= ext_cst[e.to-n-100];
			}
			else de[t.to-n-100] = true;
		}
		else m_cnt++;
		if (m_cnt == n) return ans;
		for (int i=head[t.to]; i; i = edge[i].next){
			e = edge[i];
			if (vis[e.to]) continue;
			if (e.to > n){
				q.push({e.w+ext_cst[e.to-n-100], e.to});
			}
			else q.push({e.w, e.to});
		}
	}
	return ans;
}



int main(){
	int t1, t2, t3;
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i=0;i<m;i++) {
    	scanf("%d%d%d", &t1, &t2, &t3);
    	ade(t1, t2, t3);
    	ade(t2, t1, t3);
	}
	for (int i=1;i<=k;i++){
		scanf("%d", &t1);
		ext_cst[i] = t1;
		for (int j=1;j<=n;j++){
			scanf("%d", &t2);
			ade(n+100+i, j, t2);
			ade(j, n+100+i, t2);
		}
	}
    cout << bfs();
    return 0;
}
