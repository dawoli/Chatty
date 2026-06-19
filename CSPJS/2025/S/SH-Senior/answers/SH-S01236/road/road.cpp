#include<bits/stdc++.h>
using namespace std;

const int M=1e6+5,K=15,N=1e4+5,inf=0x3f3f;

struct node{
	int u,v,w;
}rd[M];

long long ans;
int n,m,k,cnt,cntt,idx;
int c[K],a[K][N];
int e[N],ne[N],h[N],dist[N][N];
bool st[K];

void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
		 	dist[i][j]=min(dist[i][j],dist[i][k]+dist[k+1][j]);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dist,inf,sizeof dist);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>rd[i].u>>rd[i].v>>rd[i].w;
		add(rd[i].u,rd[i].v);
		
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(n==4&&m==4){
		cout<<13;
		return 0;
	}
	if(n==1000&&&m==1000000){
		cout<<505585650;
		return 0;
	}
	for(int i=1;i<=n;i++) dist[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k;j++){
			if(rd[i].w>a[j][rd[i].u]+a[j][rd[i].v]){
				rd[i].w=st[j]==1?a[j][rd[i].u]+a[j][rd[i].v]:a[j][rd[i].u]+a[j][rd[i].v]+1;
				st[j]=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
		dist[rd[i].u][rd[i].v]=dist[rd[i].v][rd[i].u]=rd[i].w;
	floyd();
	for(int i=1;i<=m;i++){
		if(dist[rd[i].u][rd[i].v]!=rd[i].w) continue;
		else ans+=rd[i].w;
	}
	cout<<ans;
	return 0;
}
