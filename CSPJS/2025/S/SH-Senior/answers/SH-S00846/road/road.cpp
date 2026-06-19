#include<bits/stdc++.h>
using namespace std;
const int N =1e3+5;
const int M =1e6+5;
struct edge{
	int u,v,w,id;
}a[M];
int n,m,k,c[15],fa[N],ans,x[11][N],p[N][N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void Kruskal(){
	sort(a+1,a+m+n+1,cmp);
	for(int i=1;i<=m+n;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(find(u)==find(v)) continue;
		ans+=w;
		merge(u,v);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++)
			cin>>a[i].u>>a[i].v>>a[i].w;
		for(int i=1;i<=n;i++) fa[i]=i;
		Kruskal();
		cout<<ans<<endl;
		return 0;	
	}
	memset(p,0x7f,sizeof(p));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		p[u][v]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>x[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=k;l++)
				p[i][j]=min(p[i][j],x[l][i]+x[l][j]+c[j]); 
		}
	}
	int cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[cnt++]={i,j,p[i][j]};
		}
	} 
	for(int i=1;i<=n;i++) fa[i]=i;
	Kruskal();
	cout<<ans<<endl;
	return 0;	
}
