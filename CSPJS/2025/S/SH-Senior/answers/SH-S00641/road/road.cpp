#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int c[10010],dis[10010];
bool vis[10010];
struct node{int id,step;};
struct edge{int to,way;};

vector<edge>mp[10010];
bool operator <(const node &a,const node &b){return a.step>b.step;}
priority_queue<node>q;
void DJ(){
	for(int i=1;i<=n;i++)dis[i]=1e18;
	vis[1]=1;
	dis[1]=0;
	
	q.push(node({1,0}));
	
	while(!q.empty()){
		node u=q.top();q.pop();
		for(int i=0;i<mp[u.id].size();i++){edge e=mp[u.id][i];
		
			int v=e.to,w=e.way;
			if(vis[v])continue;
			if(dis[v]>dis[u.id]+w){
				dis[v]=dis[u.id]+w;
				q.push(node({v,dis[v]}));
			}
		}
		vis[u.id]=1;
	}
	
	
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=n;i++){
		cin>>u>>v>>w;
		mp[u].push_back(edge({v,w}));
		mp[v].push_back(edge({u,w}));
	}
	for(int i=1,u;i<=k;i++){
		cin>>u;
		u=i+n;
		for(int j=1,cost;j<=n;j++){
			cin>>cost;
			mp[u].push_back(edge({j,0}));
			mp[j].push_back(edge({u,0}));
		}
	}
	n+=k;
	DJ();
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,dis[i]);
	cout<<ans;
	
	return 0;
}
