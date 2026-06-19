#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int>v[1000005],w[1000005];
int vis[10005],dis[10005];
int dijkstra(){
	for(int i=2;i<=n;i++){
		dis[i]=1e9;
	}
	while(1){
		int u=0;
		int mindis=1e9;
		for(int i=1;i<=n;i++){
			if(dis[i]<mindis&&vis[i]==0){
				mindis=dis[i];
				u=i;
			}
		}
		if(u==0)break;
		for(int i=0;i<v[u].size();i++){
			if(dis[v[u][i]]>dis[u]+w[u][i]){
				dis[v[u][i]]=dis[u]+w[u][i];
			}
		}
		vis[u]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dis[i]);
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		v[uu].push_back(vv);
		v[vv].push_back(uu);
		w[uu].push_back(ww);
		w[vv].push_back(ww);
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
		}
	}
	cout<<dijkstra();
	return 0;
}
