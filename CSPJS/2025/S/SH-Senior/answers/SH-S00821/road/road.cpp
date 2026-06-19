#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e4+5;
const int INF=21474836;
int n,m,k,v,u,w,cnt=0;
int minn[N],c[N];
bool vis[N];
int g[N][N],add[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(g,INF,sizeof(g));
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>add[i][j];
			if(k!=0){
				g[i][j]=add[i][j];
				g[j][i]=add[j][i];

			}
		}
		ans+=c[i];
}

	memset(vis,-1,sizeof(vis));
	memset(minn,0x7f,sizeof(minn));
	minn[1]=0;
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=1;j<=n;j++)
			if(!vis[j] && (minn[num]>minn[j]))	num=j;
		vis[k]=true;
		ans+=minn[num];
		for(int j=1;j<=n;j++){
			if(!vis[j] && (g[num][j]<minn[j]))	minn[j]=g[num][j];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
