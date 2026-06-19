#include <bits/stdc++.h>
using namespace std;
int n,m,k,c[10010];
long long ans=0;
struct node{
	int u;int v;
};
long long a[10010][10010],b[10010][10010];
//vector<vector<node> > gr(n+1);
struct no{
	int num;long long dis;
};
struct cmp{
	bool operator()(const no& x,const no& y)
	{
		return x.dis>y.dis;
	}
};
int vis[10010];
long long dis[10010];
int main(){
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	memset(dis,0x3f3f3f3f,sizeof(dis));
	memset(a,0x3f,sizeof(a));
	if(k==0){
		for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
		//gr[u].push_back({v,w});
		//gr[v].push_back({u,w});
	}
	vis[1]=1,dis[1]=0;
//	priority_queue<long long,vector<long long>,cmp> q;
//	q.push({1,dis[1]);
	for(int i=1;i<=n-1;i++)
	{
		long long min=0x3f3f3f3f;
		int minn=1;
		for(int j=1;j<=n;j++){
			if(dis[j]<min&&vis[j]==0){
				minn=j;
			}
		}
		vis[minn]=1;
		for(int j=1;j<=n;j++)
		{
			if(a[minn][j]<dis[j]&&vis[j]==0)
			{
				dis[j]=a[minn][j];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<dis[i]<<endl;
		ans+=dis[i];
	}
	cout<<ans;
	}
//	else{
//		for(int i=1;i<=k;i++)
//		{
//			cin>>c[i];
//			for(int j=1;j<=n;j++)
//			{
//				long long d;
//				cin>>d;
//				if(a[i][j]>d+c[i])
//			}
//		}
//	}
	
	return 0;
}
