#include<bits/stdc++.h>
using namespace std;
const int N=1019;
const long long INF=1e18;
long long n,m,k,res=0,dis[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=INF;
		}
	}
	for(long long i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
	}
	for(int i=1,c;i<=k;i++){
		cin>>c;
		for(long long j=1,o;j<=n;j++){
			cin>>o;
			dis[n+i][j]=min(dis[n+i][j],o);
			dis[j][n+i]=min(dis[j][n+i],o);
		}
		res+=c;
	}
	for(int co=1;co<=n+k;co++){
		for(int i=1;i<=n+k;i++){
			if(dis[i][co]==INF)continue;
			for(int j=1;j<=n+k;j++){
				dis[i][j]=min(dis[i][j],dis[i][co]+dis[co][j]);
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=max(ans,dis[i][j]);
		}
	}
	cout<<ans+res;
	return 0;
} 
