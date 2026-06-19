#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n,m,k,vis[N];
long long dis[N];
struct node{
	int to , val;
};
struct edge{
	int now ;
	long long val;
};
queue<edge> q;
vector<node> g[N];
void dij(){
	for(int i=1;i<=n;i++)dis[i] = 1e10;
	dis[1] = 0;
	q.push({1,0});
	while(!q.empty()){
		edge u = q.front();
		q.pop();
		int x = u.now;
		for(int i=0;i<g[x].size();i++){
			int y = g[x][i].to;
			int w = g[x][i].val;
			if( dis[y] > dis[x] + w){
				dis[y] = dis[x] + w;
				q.push({y,w+u.val});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	if( k == 0)
		dij();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
5 8 0
1 2 2
2 3 2
3 4 2
4 5 2
5 6 2
6 1 1
1 3 1
1 4 1
*/
