#include<bits/stdc++.h>
using namespace std;
int g[10009][10009];
int vst[10009][10009];
int a[19][10009];
int c[19];
int fa[10009];
struct node{
	int u,v,w;
};
bool cmp(node x,node y){
	return x.w<y.w;
}
long long INF=10e9+9;
int getf(int x){
	if(fa[x]==x) return x;
	return getf(fa[x]);
}
void unite(int x,int y){
	int fx=getf(x);
	int fy=getf(y);
	fa[fx]=fy;
}
node ed[1000009];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	fa[i]=i;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		if(vst[u][v])
		g[u][v]=min(g[u][v],w);
		else
		g[u][v]=w;
		vst[u][v]=1;
		vst[v][u]=1;
		g[v][u]=g[u][v];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
		cin>>a[i][j];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int h=j+1;h<=n;h++){
				if(!vst[j][h])
				g[j][h]=INF;
			g[j][h]=min(g[j][h],c[i]+a[i][j]+a[i][h]);
			vst[j][h]=1;
}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ed[++cnt].u=i;
			ed[cnt].v=j;
			ed[cnt].w=g[i][j];
		}
	}
	int sum=0;
	sort(ed+1,ed+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	cout<<ed[i].u<<" "<<ed[i].v<<" "<<ed[i].w<<endl;
	int p=0;
	for(int i=1;i<=cnt;i++){
		int fu=getf(ed[i].u);
		int fv=getf(ed[i].v);
		if(fu!=fv){
		sum+=ed[i].w;
		p++;
		unite(ed[i].u,ed[i].v);
		cout<<ed[i].w<<endl;
	}
		if(p==n-1)
		break;
	}
	cout<<sum;
}
