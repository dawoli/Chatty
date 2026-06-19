#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
vector<long long> g[10010];
vector<long long> val[10010];
long long c[15];
long long cc[10010][15];

long long getdis( ){
	long long vis[10020]={ };
	long long dis[10020]={ };
	for(long long i=1;i<=n+k;i++)
		dis[i]=1000000001;
	dis[1]=0;
	vis[1]=1;
	long long ans=1;
	long long num=0;
	queue<long long> q;
	q.push(1);
	while(ans<n){
		long long l=q.size( );
		for(long long i=0;i<l;i++){
			long long u=q.front( );
			q.pop( );
			for(long long j=0;j<g[u].size( );j++){
				long long v=g[u][j];
				dis[v]=min(dis[v],val[u][j]);
			}
		}
		long long minn=1000000001;
		for(long long i=1;i<=n+k;i++)
			if(vis[i]==0)
				minn=min(minn,dis[i]);
		for(long long i=1;i<=n+k;i++){
			if(dis[i]==minn&&vis[i]==0){
				if(i<=n){
					ans++;
					num+=dis[i];
					vis[i]=1;
					q.push(i);
				}
				else{
					num+=c[i-n];
					num+=dis[i];
					vis[i]=1;
					q.push(i);
				}
			}
		}	
	}
	return num;
}
int main( ){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=0;i<m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(v);
		val[u].push_back(w);
		g[v].push_back(u);
		val[v].push_back(w);
	}
	for(int i=1;i<=k;i++){
		int vi[10010]={ };
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>cc[j][i];
			g[n+i].push_back(j);
			g[j].push_back(n+i);
			val[n+i].push_back(cc[j][i]);
			val[j].push_back(cc[j][i]);
		}
	}
	cout<<getdis( );
	return 0;
}
