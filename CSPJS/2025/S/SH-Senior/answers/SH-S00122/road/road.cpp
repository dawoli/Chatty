#include<bits/stdc++.h>
using namespace std;
struct dat{
	int id,len;
};
int n,m,k,u,v,w;
vector<dat>g[1005];
bool vis[1005];
long long dis[1005];
void d(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	vis[s]=1;
	while(true){
		int x = 0;
		for(int i = 1;i<=n;i++){
			if(!vis[i]){
				continue;
			}
			if(dis[i]<dis[x]){
				x=i;
			}
		}
		if(x==0){
			break;
		}
		
		for(dat i:g[x]){
			if(dis[i.id]>dis[x]+i.len){
				dis[i.id]=dis[x]+i.len;
				vis[x]=1;
			}
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	d(1);
	int dd = 1;
	long long maxn = 0;
	for(int i = 1;i<=n;i++){
		if(dis[i]>maxn){
			maxn=dis[i];
			dd = i;
		}
	}
	d(dd);
	maxn=0;
	for(int i = 1;i<=n;i++){
		if(dis[i]>maxn){
			maxn=dis[i];
		}
	}
	
	cout<<maxn<<endl;
	return 0;
}
