#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,w;
	friend bool operator < (node x,node y){
		return x.w>y.w;
	}
};
vector<node> G[10010];
priority_queue<node> que;
bool visited[10010];
int n,k;
void Prim(){
	int u,w;
	long long ans = 0;
	for (int i=0;i<G[1].size();i++){
		que.push(G[1][i]);
	}
	visited[1] = true;
	for (int i=1;i<n;i++){
		while (!que.empty() && visited[que.top().v]){
			que.pop();
		}
		u = que.top().v;
		w = que.top().w;
		ans = ans+(long long)w;
		visited[u] = true;
		for (int j=0;j<G[u].size();j++){
			if (!visited[G[u][j].v]){
				que.push(G[u][j]);
			}
		}
	}
	printf("%lld",ans);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,u,v,w,c,a;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for (int i=1;i<=k;i++){
		scanf("%d",&c);
		for (int j=1;j<=n;j++){
			scanf("%d",&a);
		}
	}
	Prim();
	return 0;
}
