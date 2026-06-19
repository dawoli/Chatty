#include<bits/stdc++.h>
using namespace std;
int n,m,k,dis[1005][1005],s[1005],vis[1005];
long long ans=1e9;
void dfs(int num,long long sum,int last){
	num++;
	if(sum>ans)return;
	if(num>n){
		ans=min(sum,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(num,sum+dis[last][i],i);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e9;
			dis[j][i]=1e9;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			s[i]=w;
		}
		for(int a=1;a<n;a++){
			for(int b=a+1;b<=n;b++){
				dis[a][b]=min(dis[a][b],s[a]+s[b]+c);
				dis[b][a]=dis[a][b];
			}
		}
	}
	for(int a=1;a<n;a++){
			for(int b=a+1;b<=n;b++){
				cout<<dis[a][b]<<" "<<dis[b][a]<<endl;
			}
		}
	dfs(0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

