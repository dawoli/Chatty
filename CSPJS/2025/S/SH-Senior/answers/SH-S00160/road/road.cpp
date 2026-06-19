#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+10;
int n,m,k,a[10][N],c[10],ans;
bool vis[N];
bool vis2[N];
int dis[N][N];
vector<pair<int,int>> g[N];
void dijkstra(int x){
	vis[x] = 1;
	priority_queue<pair<int,int>>q;
	q.push({0,x});
	dis[x][x] = 0;
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		for(auto i : g[u]){
			int v = i.first;
			int w = i.second;
			dis[x][v] = min(dis[x][u]+w,dis[x][v]);
			if(!vis[v]){
				vis[v] = 1;
				q.push({dis[x][v],v});
			}
		}
	}
}
void dijkstra1(int x){
	vis[x] = 1;
	priority_queue<pair<int,int>>q;
	q.push({0,x});
	dis[x][x] = 0;
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		for(auto i : g[u]){
			int v = i.first;
			int w = i.second;
			dis[x][v] = min(w,dis[x][v]);
			if(!vis[v]){
				vis[v] = 1;
				q.push({dis[x][v],v});
			}
		}
	}
}
bool judge(int k){
	int cha = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[k][i]+a[k][j]<dis[i][j] && dis[i][j] != 0x3f){
				cha += dis[i][j]-a[k][i]-a[k][j];
			}
			if(cha>c[k]) return 1;
		}
	}
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		dis[u][u] = dis[v][v] = 0;
		dis[u][v] = dis[v][u] = w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	for(int x=1;x<=k;x++){
		if(!judge(x)) continue;
		ans += c[x];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[k][i]+a[k][j]<dis[i][j] && i!=j){
					dis[i][j] = dis[j][i] = a[k][i]+a[k][j];	
				}
			}
		}
	}
	dijkstra1(1);
	for(int i=1;i<=n;i++){
		ans+=dis[1][i];
	}
	cout<<ans;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4

